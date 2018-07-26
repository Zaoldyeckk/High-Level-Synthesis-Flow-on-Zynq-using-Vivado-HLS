#ifndef RGB2YUV_H_
#define RGB2YUV_H_

#ifdef BIT_ACCURATE
#include "autopilot_tech.h"

typedef int9  rgb2yuv_coef_t;
typedef int11 yuv2rgb_coef_t;
typedef int9  yuv_intrnl_t;
typedef uint8 yuv_scale_t;

#else // Use native C types

typedef signed short  rgb2yuv_coef_t ;
typedef signed short  yuv2rgb_coef_t;
typedef signed short  yuv_intrnl_t;
typedef unsigned char yuv_scale_t;

#endif

#include "image_aux.h"

#define CLIP(x) (((x)>255) ? 255 : (((x)<0) ? 0 : (x)))

void rgb2yuv (image_t*, image_t*);
void yuv2rgb (image_t*, image_t*);

void yuv_scale (
  image_t *in,
  image_t *out,
  yuv_scale_t Y_scale,
  yuv_scale_t U_scale,
  yuv_scale_t V_scale
  );

void yuv_filter (
  image_t *in,
  image_t *out,
  yuv_scale_t Y_scale,
  yuv_scale_t U_scale,
  yuv_scale_t V_scale
  );

#endif
