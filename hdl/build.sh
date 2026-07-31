#!/bin/bash
set -e

echo "=== 1. Synthesizing Verilog with Yosys ==="
yosys -p "synth_ecp5 -top top -json fpga/top.json" fpga/usb_test.v

echo "=== 2. Place & Route with nextpnr-ecp5 ==="
nextpnr-ecp5 --25k --package CABGA256 --json fpga/top.json --lpf fpga/pins.lpf --textcfg fpga/top.config

echo "=== 3. Packing Bitstream with ecppack ==="
ecppack fpga/top.config fpga/top.bit

echo "=== Bitstream ready: fpga/top.bit ==="
echo "To flash your iCESugar-Pro board, run:"
echo "  openFPGALoader -c cmsisdap fpga/top.bit"
