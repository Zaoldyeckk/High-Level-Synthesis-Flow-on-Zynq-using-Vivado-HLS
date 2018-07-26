# Audio Related constraints
set_property PACKAGE_PIN AA6 [get_ports BCLK]
set_property IOSTANDARD LVCMOS33 [get_ports BCLK]

set_property PACKAGE_PIN Y6 [get_ports LRCLK]
set_property IOSTANDARD LVCMOS33 [get_ports LRCLK]

set_property PACKAGE_PIN AA7 [get_ports SDATA_I]
set_property IOSTANDARD LVCMOS33 [get_ports SDATA_I]

set_property PACKAGE_PIN Y8 [get_ports SDATA_O]
set_property IOSTANDARD LVCMOS33 [get_ports SDATA_O]

#MCLK
set_property PACKAGE_PIN AB2 [get_ports FCLK_CLK1]
set_property IOSTANDARD LVCMOS33 [get_ports FCLK_CLK1]

set_property PACKAGE_PIN AB4 [get_ports IIC_1_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports IIC_1_scl_io]

set_property PACKAGE_PIN AB5 [get_ports IIC_1_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports IIC_1_sda_io]

set_property PACKAGE_PIN AB1 [get_ports {GPIO_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[0]}]

set_property PACKAGE_PIN Y5 [get_ports {GPIO_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[1]}]

# GPIO2[0] for bypass a sample or send it through the filter
set_property PACKAGE_PIN F22 [get_ports {GPIO2_tri_i[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO2_tri_i[0]}]

