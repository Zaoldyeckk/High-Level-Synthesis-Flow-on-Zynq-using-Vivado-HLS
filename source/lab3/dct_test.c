// Copyright (C) 2008 AutoESL Design Techonologies, Inc.
// All rights reserved.

#include <stdio.h>
#include "dct.h"


// ********************************************************
int main() {
   short a[N], b[N], b_expected[N];
   int retval = 0, i;
   FILE *fp;

   fp=fopen("in.dat","r");
   for (i=0; i<N; i++){
      int tmp;
      fscanf(fp, "%d", &tmp);
      a[i] = tmp;
   }
   fclose(fp);

   fp=fopen("out.golden.dat","r");
   for (i=0; i<N; i++){
      int tmp;
      fscanf(fp, "%d", &tmp);
      b_expected[i] = tmp;
   }
   fclose(fp);

   dct(a, b);

   for (i = 0; i < N; ++i) {
      if(b[i] != b_expected[i]){
         printf("Incorrect output on sample %d. Expected %d, Received %d \n", i, b_expected[i], b[i]);
         retval = 2;
      }
   }

#if 0 // Optionally write out computed values
   fp=fopen("out.dat","w");
   for (i=0; i<N; i++){
      fprintf(fp, "%d\n", b[i]);
   }
   fclose(fp);
#endif

   if(retval != (2)){
      printf("    *** *** *** *** \n");
      printf("    Results are good \n");
      printf("    *** *** *** *** \n");
   } else {
      printf("    *** *** *** *** \n");
      printf("    BAD!! %d \n", retval);
      printf("    *** *** *** *** \n");
   }
   return retval;
}
