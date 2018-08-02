############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project fir.prj
set_top fir
add_files D:/HLS_2018.2update/HLS/labsource/labs/lab4/fir.c
add_files D:/HLS_2018.2update/HLS/labsource/labs/lab4/fir_coef.dat
add_files -tb D:/HLS_2018.2update/HLS/labsource/labs/lab4/fir_test.c
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
source "./fir.prj/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
