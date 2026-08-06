VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe --trace -Wall -Wno-fatal \
	-I../hdl/packages \
	-I../hdl/common \
	-I../hdl/adc

VSRCS = ../hdl/packages/params_pkg.sv \
	../hdl/packages/utils_pkg.sv \
	../hdl/common/dual_port_dual_clk_ram.sv \
	../hdl/common/dual_clk_fifo.sv \
	../hdl/common/fwft_dual_clk_fifo.sv \
	../hdl/adc/adc_interface.sv \
	../hdl/adc/adc_wrapper.sv

TB_SRC = tb_adc_wrapper.cpp
TOP_MODULE = adc_wrapper
OBJ_DIR = obj_dir

all: sim

$(OBJ_DIR)/V$(TOP_MODULE): $(VSRCS) $(TB_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) $(VSRCS) $(TB_SRC) --top-module $(TOP_MODULE) -Mdir $(OBJ_DIR)
	make -C $(OBJ_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

sim: $(OBJ_DIR)/V$(TOP_MODULE)
	./$(OBJ_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(OBJ_DIR) *.vcd

.PHONY: all sim clean
