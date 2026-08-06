#include <iostream>
#include <iomanip>
#include <memory>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vtop>();
    auto tfp = std::make_unique<VerilatedVcdC>();
    top->trace(tfp.get(), 99);
    tfp->open("tb_top.vcd");

    vluint64_t main_time = 0;

    // Initial signals
    top->clk_25m = 0;
    top->ulpi_clk60 = 0;
    top->ulpi_dir = 0;
    top->ulpi_nxt = 1; // Pretend PHY is always ready to accept TX data
    top->adc_otr = 0;
    top->adc_data_raw = 0x800;

    std::cout << "[SIM] Starting Top-Level Verification...\n";

    vluint64_t clk_25m_period = 40;  // 25 MHz (40ns full period)
    vluint64_t ulpi_clk_period = 16;  // 60 MHz (~16ns full period)

    vluint64_t next_adc_toggle = clk_25m_period / 2;
    vluint64_t next_ulpi_toggle = ulpi_clk_period / 2;

    while (main_time < 120000000 && !Verilated::gotFinish()) { // 120 ms
        // Toggle 25 MHz Clock
        if (main_time >= next_adc_toggle) {
            top->clk_25m = !top->clk_25m;
            next_adc_toggle += clk_25m_period / 2;
            if (top->clk_25m) {
                top->adc_data_raw = (top->adc_data_raw + 1) & 0xFFF;
            }
        }

        // Toggle 60 MHz Clock
        if (main_time >= next_ulpi_toggle) {
            top->ulpi_clk60 = !top->ulpi_clk60;
            next_ulpi_toggle += ulpi_clk_period / 2;
        }

        top->eval();
        if (main_time > 109900000) { // Only dump after 109.9ms to save VCD size
            tfp->dump(main_time);
        }
        main_time++;
    }

    tfp->close();
    std::cout << "[SIM] Simulation finished.\n";
    std::cout << "[SIM] Waveform dumped to: verification/tb_top.vcd\n";
    return 0;
}
