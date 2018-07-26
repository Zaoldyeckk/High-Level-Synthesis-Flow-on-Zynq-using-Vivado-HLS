start_gui
create_project audio ./audio -part xc7z010clg400-1
set_property board_part digilentinc.com:zybo:part0:1.0 [current_project]
set_property simulator_language Verilog [current_project]
create_bd_design "system"
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable" }  [get_bd_cells processing_system7_0]
regenerate_bd_layout
startgroup
set_property -dict [list CONFIG.PCW_FPGA1_PERIPHERAL_FREQMHZ {12.288} CONFIG.PCW_EN_CLK1_PORT {1} CONFIG.PCW_ENET0_PERIPHERAL_ENABLE {0} CONFIG.PCW_SD0_PERIPHERAL_ENABLE {0} CONFIG.PCW_USB0_PERIPHERAL_ENABLE {0} CONFIG.PCW_I2C1_PERIPHERAL_ENABLE {1} CONFIG.PCW_GPIO_MIO_GPIO_ENABLE {0}] [get_bd_cells processing_system7_0]
endgroup
regenerate_bd_layout
startgroup
set_property -dict [list CONFIG.PCW_TTC0_PERIPHERAL_ENABLE {0}] [get_bd_cells processing_system7_0]
endgroup
regenerate_bd_layout
set_property ip_repo_paths  C:/xup/hls/labs/lab4/ip_repo [current_project]
update_ip_catalog
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_gpio:2.0 axi_gpio_0
endgroup
startgroup
set_property -dict [list CONFIG.C_GPIO_WIDTH {1} CONFIG.C_GPIO2_WIDTH {1} CONFIG.C_IS_DUAL {1} CONFIG.C_ALL_INPUTS_2 {1} CONFIG.C_ALL_OUTPUTS {1}] [get_bd_cells axi_gpio_0]
endgroup
startgroup
create_bd_cell -type ip -vlnv xilinx.com:xilinx:zybo_audio_ctrl:1.0 zybo_audio_ctrl_0
endgroup
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" Clk "Auto" }  [get_bd_intf_pins axi_gpio_0/S_AXI]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" Clk "Auto" }  [get_bd_intf_pins zybo_audio_ctrl_0/S_AXI]
startgroup
create_bd_intf_port -mode Master -vlnv xilinx.com:interface:gpio_rtl:1.0 GPIO
connect_bd_intf_net [get_bd_intf_pins axi_gpio_0/GPIO] [get_bd_intf_ports GPIO]
endgroup
startgroup
create_bd_intf_port -mode Master -vlnv xilinx.com:interface:gpio_rtl:1.0 GPIO2
connect_bd_intf_net [get_bd_intf_pins axi_gpio_0/GPIO2] [get_bd_intf_ports GPIO2]
endgroup
set_property range 64K [get_bd_addr_segs {processing_system7_0/Data/SEG_zybo_audio_ctrl_0_reg0}]
startgroup
create_bd_port -dir O BCLK
connect_bd_net [get_bd_pins /zybo_audio_ctrl_0/BCLK] [get_bd_ports BCLK]
endgroup
startgroup
create_bd_port -dir O PBLRCLK
connect_bd_net [get_bd_pins /zybo_audio_ctrl_0/PBLRCLK] [get_bd_ports PBLRCLK]
endgroup
startgroup
create_bd_port -dir O RECLRCLK
connect_bd_net [get_bd_pins /zybo_audio_ctrl_0/RECLRCLK] [get_bd_ports RECLRCLK]
endgroup
startgroup
create_bd_port -dir O PBDATA
connect_bd_net [get_bd_pins /zybo_audio_ctrl_0/PBDATA] [get_bd_ports PBDATA]
endgroup
startgroup
create_bd_port -dir I RECDAT
connect_bd_net [get_bd_pins /zybo_audio_ctrl_0/RECDAT] [get_bd_ports RECDAT]
endgroup
startgroup
create_bd_intf_port -mode Master -vlnv xilinx.com:interface:iic_rtl:1.0 IIC_1
connect_bd_intf_net [get_bd_intf_pins processing_system7_0/IIC_1] [get_bd_intf_ports IIC_1]
endgroup
startgroup
create_bd_port -dir O -type clk FCLK_CLK1
connect_bd_net [get_bd_pins /processing_system7_0/FCLK_CLK1] [get_bd_ports FCLK_CLK1]
endgroup
regenerate_bd_layout
