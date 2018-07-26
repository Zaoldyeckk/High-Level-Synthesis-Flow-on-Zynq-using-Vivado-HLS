#include "fir.h" 

void fir (
  data_t *y,
  data_t x
  ) {
  const coef_t c[N+1]={
 #include "fir_coef.dat"
    };
  

  static data_t shift_reg[N];
  acc_t acc;
  int i;
  
  acc=(acc_t)shift_reg[N-1]*(acc_t)c[N];
  loop: for (i=N-1;i!=0;i--) {
    acc+=(acc_t)shift_reg[i-1]*(acc_t)c[i];
    shift_reg[i]=shift_reg[i-1];
  }
  acc+=(acc_t)x*(acc_t)c[0];
  shift_reg[0]=x;
  *y = acc>>15;
}
