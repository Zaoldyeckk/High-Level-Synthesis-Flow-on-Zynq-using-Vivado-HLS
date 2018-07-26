
open_project dct.prj
set_top dct

add_file dct.c
add_file -tb dct_test.c
add_file -tb in.dat
add_file -tb out.golden.dat

open_solution solution1 -reset
set_part  {xc7z020clg484-1}
create_clock -period 10ns

csynth_design

exit