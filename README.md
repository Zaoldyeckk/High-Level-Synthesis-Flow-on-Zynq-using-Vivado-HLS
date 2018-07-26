# High-Level-Synthesis-Flow-on-Zynq-using-Vivado-HLS

This course provides professors with an understanding of high-level synthesis design methodologies necessary to develop digital systems using Vivado HLS. Now under 2018.2 version.

## Source Files Setup


To use the source files for each of the labs in this workshop, you have to clone this repository from XUP Github. For that, do the following:

#### To be completed

---
#### In the instructions for the labs;

**{sources}** refers to C:\xup\adv_embedded\2018_2_zynq_sources. You can download the source files for the labs from [here](https://www.xilinx.com/support/university/vivado/vivado-workshops/Vivado-adv-embedded-design-zynq.html)

**{labs}** refers to C:\xup\adv_embedded\2018_2_zynq_lab. It assumes that you will create the mentioned directory structure to carry out the labs of this workshop

**{labsolutions}** refers to [here](https://www.xilinx.com/support/university/vivado/vivado-workshops/Vivado-adv-embedded-design-zynq.html). This will require you to login into your Xilinx account.

---
**NOTE**

Board support for the PYNQ-Z1 and PYNQ-Z2 are not included in Vivado 2018.2 by default. The relevant files need to be extracted and saved to:

 {Vivado installation}\data\boards\board_files\zynq

These files can be downloaded from [/board_files](https://www.xilinx.com/support/university/vivado/vivado-workshops/Vivado-adv-embedded-design-zynq.html). 

---

## Hardware Setup


**PYNQ-Z2**:  Connect the board to the PC using a micro USB cable. Make sure that a jumper is connected to JTAG (between JP1_1 and JP1_2) to use the board in the development mode.  Also, make sure that another jumper is placed between J9_2 and J9_3 to select USB as a power source.
