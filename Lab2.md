# Improving Performance Lab

## Introduction

This lab introduces various techniques and directives which can be used in Vivado HLS to improve
design performance. The design under consideration accepts an image in a (custom) RGB format,
converts it to the Y’UV color space, applies a filter to the Y’UV image and converts it back to RGB.

## Objectives

After completing this lab, you will be able to:

* Add directives in your design
* Understand the effect of INLINE directive
* Improve performance using PIPELINE directive
* Distinguish between DATAFLOW directive and Configuration Command functionality

## Steps

### Create a Vivado HLS Project from Command Line

#### Validate your design using Vivado HLS command line window. Create a new Vivado HLS project from the command line.

1-1-1. Launch Vivado HLS: **Select Start > All Programs > Xilinx Design Tools > Vivado 2018.2 > Vivado HLS > Vivado HLS 2018.2 Command Prompt**.

1-1-2. In the Vivado HLS Command Prompt, change directory to c:\xup\hls\labs\lab2.

1-1-3. A self-checking program (yuv_filter_test.c) is provided. Using that we can validate the design. A Makefile is also provided. Using the Makefile, the necessary source files can be compiled and the compiled program can be executed. You can examine the contents of these files and the project directory. In the Vivado HLS Command Prompt, type make to compile and execute the program.
    <p align="center">
    <img src ="./images/lab2/Figure1.png" width="60%" height="80%"/>
    </p>
    <p align = "center">
    <i>Figure 1. Validating the design</i>
    </p>
Note that the source files (yuv_filter.c, yuv_filter_test.c, and image_aux.c) were compiled, then
yuv_filter executable program was created, and then it was executed. The program tests the
design and outputs Test Passed message.

1-1-4. A Vivado HLS tcl script file (yuv_filter.tcl) is provided and can be used to create a Vivado HLS project.

