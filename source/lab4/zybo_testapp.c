
#include "zybo_audio.h"
#include <stdio.h>
#include <xil_io.h>
#include <sleep.h>
#include "xiicps.h"
#include <xil_printf.h>
#include <xparameters.h>
#include "xfir.h"
#include "xuartps.h"
#include "xscutimer.h"
#include "xscugic.h"

typedef short		Xint16;
typedef long		Xint32;
#define TIMER_FREQ_HZ (XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ / 2)

unsigned char IicConfig(unsigned int DeviceIdPS);
void AudioWriteToReg(unsigned char u8RegAddr, short u16Data);
void LineinLineoutConfig();

XIicPs Iic;
XScuTimer TimerInstance;

// HLS FIR HW instance
XFir HlsFir_left, HlsFir_right;
//Interrupt Controller Instance
XScuGic ScuGic;
//Global variables used by ISR
int ResultAvailHlsFir_left, ResultAvailHlsFir_right;

int hls_fir_init(XFir *hls_firPtr_left, XFir *hls_firPtr_right)
{
   XFir_Config *cfgPtr_left, *cfgPtr_right;
   int status;

   cfgPtr_left = XFir_LookupConfig(XPAR_FIR_LEFT_DEVICE_ID);
   if (!cfgPtr_left) {
      print("ERROR: Lookup of Left FIR configuration failed.\n\r");
      return XST_FAILURE;
   }
   status = XFir_CfgInitialize(hls_firPtr_left, cfgPtr_left);
   if (status != XST_SUCCESS) {
      print("ERROR: Could not initialize left FIR.\n\r");
      return XST_FAILURE;
   }

   cfgPtr_right = XFir_LookupConfig(XPAR_FIR_RIGHT_DEVICE_ID);
   if (!cfgPtr_right) {
      print("ERROR: Lookup of Right FIR configuration failed.\n\r");
      return XST_FAILURE;
   }
   status = XFir_CfgInitialize(hls_firPtr_right, cfgPtr_right);
   if (status != XST_SUCCESS) {
      print("ERROR: Could not initialize right FIR.\n\r");
      return XST_FAILURE;
   }

   return status;
}

int TimerInitialize(void)
{
	int Status;
	XScuTimer *TimerInstancePtr = &TimerInstance;
	XScuTimer_Config *ConfigTmrPtr;

	/* Initialize the Scu Private Timer driver. */
	ConfigTmrPtr = XScuTimer_LookupConfig(XPAR_PS7_SCUTIMER_0_DEVICE_ID);

	/* This is where the virtual address would be used, this uses physical address. */
	Status = XScuTimer_CfgInitialize(TimerInstancePtr, ConfigTmrPtr,
			ConfigTmrPtr->BaseAddr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Disable Auto reload mode and set prescaler to 1 */
	XScuTimer_SetPrescaler(TimerInstancePtr, 0);

	return Status;
}

void TimerDelay(u32 uSDelay)
{
	u32 timerCnt;

	timerCnt = (TIMER_FREQ_HZ / 1000000) * uSDelay;

	XScuTimer_Stop(&TimerInstance);
	XScuTimer_DisableAutoReload(&TimerInstance);
	XScuTimer_LoadTimer(&TimerInstance, timerCnt);
	XScuTimer_Start(&TimerInstance);
	while (XScuTimer_GetCounterValue(&TimerInstance))
	{}

	return;
}
void hls_fir_left_isr(void *InstancePtr)
{
	   XFir *pAccelerator = (XFir *)InstancePtr;

	   // clear the local interrupt
	   XFir_InterruptClear(pAccelerator,1);

	   ResultAvailHlsFir_left = 1;
}

void hls_fir_right_isr(void *InstancePtr)
{
	   XFir *pAccelerator = (XFir *)InstancePtr;

	   // clear the local interrupt
	   XFir_InterruptClear(pAccelerator,1);

	   ResultAvailHlsFir_right = 1;
}

int setup_interrupt()
{
	   //This functions sets up the interrupt on the ARM
	   int result;
	   XScuGic_Config *pCfg = XScuGic_LookupConfig(XPAR_SCUGIC_0_DEVICE_ID);
	   if (pCfg == NULL){
	      print("Interrupt Configuration Lookup Failed\n\r");
	      return XST_FAILURE;
	   }
	   result = XScuGic_CfgInitialize(&ScuGic,pCfg,pCfg->CpuBaseAddress);
	   if(result != XST_SUCCESS){
	      return result;
	   }
	   // self test
	   result = XScuGic_SelfTest(&ScuGic);
	   if(result != XST_SUCCESS){
	      return result;
	   }
	   // Initialize the exception handler
	   Xil_ExceptionInit();
	   // Register the exception handler
	   Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,(Xil_ExceptionHandler)XScuGic_InterruptHandler,&ScuGic);
	   //Enable the exception handler
	   Xil_ExceptionEnable();
	   // Connect the Left FIR ISR to the exception table
	   result = XScuGic_Connect(&ScuGic,XPAR_FABRIC_FIR_LEFT_INTERRUPT_INTR,(Xil_InterruptHandler)hls_fir_left_isr,&HlsFir_left);
	   if(result != XST_SUCCESS){
	      return result;
	   }
	   // Connect the Right FIR ISR to the exception table
	   result = XScuGic_Connect(&ScuGic,XPAR_FABRIC_FIR_RIGHT_INTERRUPT_INTR,(Xil_InterruptHandler)hls_fir_right_isr,&HlsFir_right);
	   if(result != XST_SUCCESS){
	      return result;
	   }
	   // Enable the Left FIR ISR
	   XScuGic_Enable(&ScuGic,XPAR_FABRIC_FIR_LEFT_INTERRUPT_INTR);
	   // Enable the Right FIR ISR
	   XScuGic_Enable(&ScuGic,XPAR_FABRIC_FIR_RIGHT_INTERRUPT_INTR);
	   return XST_SUCCESS;
}

void filter_or_bypass_input(void)
{
	unsigned long u32DataL, u32DataR;
	unsigned long u32Temp;
	int sw_check;

	while (1)
	{
		do //wait for RX data to become available
		{
			u32Temp = Xil_In32(I2S_STATUS_REG);
		} while ( u32Temp == 0);

		Xil_Out32(I2S_STATUS_REG, 0x00000001); //Clear data rdy bit

		u32DataL = Xil_In32(I2S_DATA_RX_L_REG);
		u32DataR = Xil_In32(I2S_DATA_RX_R_REG);
		sw_check = Xil_In32(XPAR_AXI_GPIO_0_BASEADDR+8);
		if(sw_check & 01) // SW0=1 then pass the sample through the filter
		{
			// send samples after shifting least significant 8 bits as the filter
			// requires 16 bit input sample
			XFir_Set_x(&HlsFir_left, u32DataL >> 8);
			XFir_Set_x(&HlsFir_right, u32DataR >> 8);
			// Clear done flags
			ResultAvailHlsFir_left = 0;
			ResultAvailHlsFir_right = 0;
			// issue start
			XFir_Start(&HlsFir_left);
			XFir_Start(&HlsFir_right);
			// wait for done interrupt on each channel and then read the corresponding output sample
		    while(!ResultAvailHlsFir_left);
		    u32DataL = XFir_Get_y(&HlsFir_left);
		    while(!ResultAvailHlsFir_right);
			u32DataR = XFir_Get_y(&HlsFir_right);
			// shift left by 8 bits as output sample is 16 bit whereas CODEC requires 24 bits
			u32DataL = u32DataL << 8;
			u32DataR = u32DataR << 8;
		}
		Xil_Out32(I2S_DATA_TX_L_REG, u32DataL);
		Xil_Out32(I2S_DATA_TX_R_REG, u32DataR);
		u32DataL = Xil_In32(I2S_DATA_RX_L_REG);
		u32DataR = Xil_In32(I2S_DATA_RX_R_REG);
	}
}


int main(void)
{
	int status;

	//Configure the IIC data structure
	IicConfig(XPAR_XIICPS_0_DEVICE_ID);

	// Initialize PS7 timer
	TimerInitialize();

	//Configure the Line in and Line out ports.
	LineinLineoutConfig();

	xil_printf("ADAU1761 configured\n\r");
	Xil_Out32(XPAR_AXI_GPIO_0_BASEADDR, 0b1);
	Xil_Out32(XPAR_AXI_GPIO_0_BASEADDR + 0x4, 0b0);

	// Setup the FIR instances
	status=hls_fir_init(&HlsFir_left, &HlsFir_right);
    if(status != XST_SUCCESS){
	   print("HLS peripheral setup failed\n\r");
	   return(-1);
    }

    //Setup the interrupt
    status = setup_interrupt();
    if(status != XST_SUCCESS){
       print("Interrupt setup failed\n\r");
       return(-1);
    }

    // Enable Global and instance interrupts
    XFir_InterruptEnable(&HlsFir_left,1);
    XFir_InterruptGlobalEnable(&HlsFir_left);
    XFir_InterruptEnable(&HlsFir_right,1);
    XFir_InterruptGlobalEnable(&HlsFir_right);

	ResultAvailHlsFir_left = 0;
	ResultAvailHlsFir_right = 0;

	filter_or_bypass_input(); // check SW0 in the function.  If 1 then filter otherwise bypasss
	return 0;
}

unsigned char IicConfig(unsigned int DeviceIdPS)
{

	XIicPs_Config *Config;
	int Status;

	//Initialize the IIC driver so that it's ready to use
	//Look up the configuration in the config table, then initialize it.
	Config = XIicPs_LookupConfig(DeviceIdPS);
	if(NULL == Config) {
		return XST_FAILURE;
	}

	Status = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	//Set the IIC serial clock rate.
	XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);

	return XST_SUCCESS;
}


/******************************************************************************
 * Function to write 9-bits to one of the registers from the audio
 * controller.
 * @param	u8RegAddr is the register address.
 * @param	u16Data is the data word to write ( only least significant 9 bits).
  * @return	none.
 *****************************************************************************/
void AudioWriteToReg(unsigned char u8RegAddr, short u16Data) {

	unsigned char u8TxData[2];

	u8TxData[0] = (u8RegAddr << 1 ) | ((u16Data >> 8) & 0x01); // append msb of 9-bit data to the reg addr after shifting left
	u8TxData[1] = u16Data & 0xFF;

	XIicPs_MasterSendPolled(&Iic, u8TxData, 2, IIC_SLAVE_ADDR);
	while(XIicPs_BusIsBusy(&Iic));
}

/******************************************************************************
 * Configures Line-In input, ADC's, DAC's, Line-Out and HP-Out.
 * @param   none.
 * @return	none.
 *****************************************************************************/
void LineinLineoutConfig() {

	// software reset
	AudioWriteToReg(R15_SOFTWARE_RESET, 0x000);
	TimerDelay(75000);
	// power mgmt: 0_00110010=>0,Power up, power up, OSC dn, out off, DAC up, ADC up, MIC off, LineIn up
	AudioWriteToReg(R6_POWER_MANAGEMENT, 0x030);
	// left ADC Input: 0_01010111=>0,mute disable, Line volume 0 dB
	AudioWriteToReg(R0_LEFT_ADC_INPUT,0x017);
	// right ADC Input: 0_00010111=>0,mute disable, Line volume 0 dB
	AudioWriteToReg(R1_RIGHT_ADC_INPUT,0x017);
	AudioWriteToReg(R2_LEFT_DAC_VOLUME,0x079);
	AudioWriteToReg(R3_RIGHT_DAC_VOLUME,0x079);
	// analog audio path: 0_00010010=>0,-6 dB side attenuation, sidetone off, DAC selected, bypass disabled, line input, mic mute disabled, 0 dB mic
	AudioWriteToReg(R4_ANALOG_AUDIO_PATH, 0x012);
	// digital audio path: 0_00000000=>0_000, clear offset, no mute, no de-emphasize, adc high-pass filter enabled
	AudioWriteToReg(R5_DIGITAL_AUDIO_PATH, 0x000);
	// digital audio interface: 0_00001110=>0, BCLK not inverted, slave mode, no l-r swap, normal LRC and PBRC, 24-bit, I2S mode
	AudioWriteToReg(R7_DIGITAL_AUDIO_INTERFACE, 0x00A);
	TimerDelay(75000);
	// Digital core:0_00000001=>0_0000000, activate core
	AudioWriteToReg(R9_ACTIVE, 0x001);
	// power mgmt: 0_00100010 0_Power up, power up, OSC dn, out ON, DAC up, ADC up, MIC off, LineIn up
	AudioWriteToReg(R6_POWER_MANAGEMENT, 0x022); // power mgmt: 001100010 turn on OUT

}

