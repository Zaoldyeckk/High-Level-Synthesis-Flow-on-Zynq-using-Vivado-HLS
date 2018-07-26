#ifndef IMAGE_AUX_H_
#define IMAGE_AUX_H_

#ifdef BIT_ACCURATE
#include "autopilot_tech.h"

typedef uint8  image_pix_t;
typedef uint11 image_dim_t;

#else // Use native C types

typedef unsigned char  image_pix_t;
typedef unsigned short image_dim_t;

#endif // ifdef BIT_ACCURATE

#define WIDTH 1920
#define HEIGHT 1280

typedef struct {
   image_pix_t ch1[WIDTH][HEIGHT];
   image_pix_t ch2[WIDTH][HEIGHT];
   image_pix_t ch3[WIDTH][HEIGHT];
} channel_t;

typedef struct {
   channel_t channels;
   image_dim_t width;
   image_dim_t height;
} image_t;

void image_read(image_t *in_image);

void image_write(image_t *out_image);

#endif
