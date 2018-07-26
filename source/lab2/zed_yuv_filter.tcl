# This TCL script sets up the project and initial solution
# then runs synthesis that solution

open_project -reset yuv_filter.prj
add_files yuv_filter.c
add_files -tb image_aux.c
add_files -tb yuv_filter_test.c
add_files -tb test_data

set_top yuv_filter

open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10

csynth_design

exit
