# 1 "yuv_filter.c"
# 1 "yuv_filter.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "C:/Xilinx/Vivado/2018.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 300 "C:/Xilinx/Vivado/2018.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "yuv_filter.c" 2
# 1 "./yuv_filter.h" 1
# 14 "./yuv_filter.h"
typedef signed short rgb2yuv_coef_t ;
typedef signed short yuv2rgb_coef_t;
typedef signed short yuv_intrnl_t;
typedef unsigned char yuv_scale_t;




# 1 "./image_aux.h" 1
# 12 "./image_aux.h"
typedef unsigned char image_pix_t;
typedef unsigned short image_dim_t;






typedef struct {
   image_pix_t ch1[1920][1280];
   image_pix_t ch2[1920][1280];
   image_pix_t ch3[1920][1280];
} channel_t;

typedef struct {
   channel_t channels;
   image_dim_t width;
   image_dim_t height;
} image_t;

void image_read(image_t *in_image);

void image_write(image_t *out_image);
# 21 "./yuv_filter.h" 2




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
# 1 "yuv_filter.c" 2



void yuv_filter (
      image_t *in,
      image_t *out,
      yuv_scale_t Y_scale,
      yuv_scale_t U_scale,
      yuv_scale_t V_scale
      )
{





   image_t _yuv;
   image_t _scale;
   image_t *yuv = &_yuv;
   image_t *scale = &_scale;


   rgb2yuv (in, yuv);
   yuv_scale ( yuv, scale, Y_scale, U_scale, V_scale);
   yuv2rgb ( scale, out);
}


void rgb2yuv (
      image_t *in,
      image_t *out
      )
{
   image_dim_t x, y;
   image_dim_t width, height;
   image_pix_t R, G, B, Y, U, V;
   const rgb2yuv_coef_t Wrgb[3][3] = {
      { 66, 129, 25},
      {-38, -74, 112},
      {122, -94, -18},
   };
_ssdm_SpecConstant(Wrgb);
# 37 "yuv_filter.c"


   width = in->width;
   height = in->height;
   out->width = width;
   out->height = height;

RGB2YUV_LOOP_X:
   for (x=0; x<width; x++) {
#pragma HLS loop_tripcount min=200 max=1920
RGB2YUV_LOOP_Y:
      for (y=0; y<height; y++) {
#pragma HLS loop_tripcount min=200 max=1280
 R = in->channels.ch1[x][y];
         G = in->channels.ch2[x][y];
         B = in->channels.ch3[x][y];
         Y = ((Wrgb[0][0] * R + Wrgb[0][1] * G + Wrgb[0][2] * B + 128) >> 8) + 16;
         U = ((Wrgb[1][0] * R + Wrgb[1][1] * G + Wrgb[1][2] * B + 128) >> 8) + 128;
         V = ((Wrgb[2][0] * R + Wrgb[2][1] * G + Wrgb[2][2] * B + 128) >> 8) + 128;
         out->channels.ch1[x][y] = Y;
         out->channels.ch2[x][y] = U;
         out->channels.ch3[x][y] = V;
      }
   }
}

void yuv2rgb (
      image_t *in,
      image_t *out
      )
{
   image_dim_t x,y;
   image_dim_t width, height;
   image_pix_t R, G, B;
   image_pix_t Y, U, V;
   yuv_intrnl_t C, D, E;
   const yuv2rgb_coef_t Wyuv[3][3] = {
      {298, 0, 409},
      {298, -100, -208},
      {298, 516, 0},
   };
_ssdm_SpecConstant(Wyuv);
# 77 "yuv_filter.c"


   width = in->width;
   height = in->height;
   out->width = width;
   out->height = height;

YUV2RGB_LOOP_X:
   for (x=0; x<width; x++) {
#pragma HLS loop_tripcount min=200 max=1920
YUV2RGB_LOOP_Y:
      for (y=0; y<height; y++) {
#pragma HLS loop_tripcount min=200 max=1280
 Y = in->channels.ch1[x][y];
         U = in->channels.ch2[x][y];
         V = in->channels.ch3[x][y];
         C = Y - 16;
         D = U - 128;
         E = V - 128;
         R = (((( Wyuv[0][0] * C + Wyuv[0][2] * E + 128) >> 8)>255) ? 255 : (((( Wyuv[0][0] * C + Wyuv[0][2] * E + 128) >> 8)<0) ? 0 : (( Wyuv[0][0] * C + Wyuv[0][2] * E + 128) >> 8)));
         G = (((( Wyuv[1][0] * C + Wyuv[1][1] * D + Wyuv[1][2] * E + 128) >> 8)>255) ? 255 : (((( Wyuv[1][0] * C + Wyuv[1][1] * D + Wyuv[1][2] * E + 128) >> 8)<0) ? 0 : (( Wyuv[1][0] * C + Wyuv[1][1] * D + Wyuv[1][2] * E + 128) >> 8)));
         B = (((( Wyuv[2][0] * C + Wyuv[2][1] * D + 128) >> 8)>255) ? 255 : (((( Wyuv[2][0] * C + Wyuv[2][1] * D + 128) >> 8)<0) ? 0 : (( Wyuv[2][0] * C + Wyuv[2][1] * D + 128) >> 8)));
         out->channels.ch1[x][y] = R;
         out->channels.ch2[x][y] = G;
         out->channels.ch3[x][y] = B;
      }
   }
}

void yuv_scale (
      image_t *in,
      image_t *out,
      yuv_scale_t Y_scale,
      yuv_scale_t U_scale,
      yuv_scale_t V_scale
      )
{
   image_dim_t x,y;
   image_dim_t width, height;
   image_pix_t Y, U, V;
   yuv_intrnl_t Yn, Un, Vn;

   width = in->width;
   height = in->height;
   out->width = width;
   out->height = height;

YUV_SCALE_LOOP_X:
   for (x=0; x<width; x++) {
#pragma HLS loop_tripcount min=200 max=1920
YUV_SCALE_LOOP_Y:
      for (y=0; y<height; y++) {
#pragma HLS loop_tripcount min=200 max=1280
 Y = in->channels.ch1[x][y];
         U = in->channels.ch2[x][y];
         V = in->channels.ch3[x][y];
         Yn = (Y * Y_scale) >> 7;
         Un = (U * U_scale) >> 7;
         Vn = (V * V_scale) >> 7;
         out->channels.ch1[x][y] = Yn;
         out->channels.ch2[x][y] = Un;
         out->channels.ch3[x][y] = Vn;
      }
   }
}
