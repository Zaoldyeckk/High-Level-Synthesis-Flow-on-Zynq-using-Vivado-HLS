#include <stdio.h>
#include <stdlib.h>
#include "yuv_filter.h"

int main () {
   // Dynamically allocate image buffers as they are rather large
   // and stack overflow may occur if statically allocated
   image_t *img_rgb = (image_t *)malloc(sizeof(image_t));
   image_t *img_restore = (image_t *)malloc(sizeof(image_t));

   // Read input image
   image_read(img_rgb);

   // Create output image
   // Scale should be <=128 (128 corresponds to a scale of 1.0)
   yuv_filter(img_rgb, img_restore, 128, 128, 128);

   // Save output image
   image_write(img_restore);

   // Compare results
   int ret = system("diff --brief -w test_data/output.dat test_data/output.golden.dat");

   if (ret != 0) {
      printf("Test failed!!!\n", ret);
      return 1;
   } else {
      printf("Test passed!\n", ret);
      return 0;
   }
}

