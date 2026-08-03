TARGET=top
TOP=top

VSRCS = packages/params_pkg.sv \
	packages/utils_pkg.sv \
	adc/ODDRX1F.v \
	adc/adc_interface.sv \
	adc/dual_port_dual_clk_ram.sv \
	adc/dual_clk_fifo.sv \
	adc/adc_wrapper.sv \
	adc/sine_gen.v \
	top.v \
	usb/ulpi_wrapper.v \
	usb/usb_cdc_core.v \
	usb/usb_desc_rom.v \
	usb/usbf_crc16.v \
	usb/usbf_device_core.v \
	usb/usbf_sie_rx.v \
	usb/usbf_sie_tx.v

all: ${TARGET}.bit

$(TARGET).json: $(VSRCS)
	yosys -p "read_verilog -sv -I usb -I packages -I adc $(VSRCS); synth_ecp5 -top top -json $@"

$(TARGET)_out.config: $(TARGET).json
	nextpnr-ecp5 --25k --package CABGA256 --speed 6 --placer heap --json $< --textcfg $@ --lpf pins.lpf

$(TARGET).bit: $(TARGET)_out.config
	ecppack --svf ${TARGET}.svf $< $@

${TARGET}.svf : ${TARGET}.bit

prog: ${TARGET}.bit
	@MOUNT_POINT=$$(ls -d /run/media/*/iCELink 2>/dev/null | head -n 1); \
	if [ -z "$$MOUNT_POINT" ]; then \
		udisksctl mount -b /dev/sda || udisksctl mount -b /dev/disk/by-label/iCELink; \
		MOUNT_POINT=$$(ls -d /run/media/*/iCELink 2>/dev/null | head -n 1); \
	fi; \
	echo "Programming via $$MOUNT_POINT ..."; \
	cp $(TARGET).bit "$$MOUNT_POINT/$(TARGET).bit"; \
	sync; \
	echo "Programming complete!"

clean:
	rm -f *.svf *.bit *.config *.ys *.json

.PHONY: prog clean
