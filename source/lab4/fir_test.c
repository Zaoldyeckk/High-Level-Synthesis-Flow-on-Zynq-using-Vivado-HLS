#include <stdio.h>
#include <math.h> 
#include "fir.h"
void fir (
  data_t *y,
  data_t x
  );

int main () {
  FILE   *fp;

  data_t signal, output;

  fp=fopen("fir_impulse.dat","w");
  int i;
  for (i=0;i<SAMPLES;i++) {
	  if(i==0)
		  signal = 0x8000;
	  else
		  signal = 0;
	  fir(&output,signal);
   	  printf("%i %d %d\n",i,(int)signal,(int)output);
//   	  fprintf(fp,"%i %d %d\n",i,signal,output);
  }
  fclose(fp);
  return 0;
}
