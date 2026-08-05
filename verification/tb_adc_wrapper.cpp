#include <iostream>
#include <iomanip>
#include <memory>
#include "Vadc_wrapper.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vadc_wrapper>();
    auto tfp = std::make_unique<VerilatedVcdC>();
    top->trace(tfp.get(), 99);
    tfp->open("tb_adc_wrapper.vcd");

    vluint64_t main_time = 0;

    // Initial signals
    top->rst = 1;
    top->enable = 0;
    top->adc_clk = 0;
    top->ulpi_clk = 0;
    top->tx_ready = 1;
    top->adc_data_raw = 0x800;
    top->adc_otr = 0;

    std::cout << "[SIM] Starting ADC Wrapper Verification...\n";

    vluint64_t adc_clk_period = 20;  // 25 MHz (40ns full period)
    vluint64_t ulpi_clk_period = 8;  // 60 MHz (~16.6ns full period)

    vluint64_t next_adc_toggle = adc_clk_period;
    vluint64_t next_ulpi_toggle = ulpi_clk_period;

    bool prev_tx_valid = false;
    uint64_t bytes_sent = 0;

    while (main_time < 80000 && !Verilated::gotFinish()) {
        // Toggle ADC Clock (25 MHz)
        if (main_time >= next_adc_toggle) {
            top->adc_clk = !top->adc_clk;
            next_adc_toggle += adc_clk_period;
            if (top->adc_clk) {
                top->adc_data_raw = (top->adc_data_raw + 1) & 0xFFF;
            }
        }

        // Toggle ULPI Clock (60 MHz)
        if (main_time >= next_ulpi_toggle) {
            top->ulpi_clk = !top->ulpi_clk;
            next_ulpi_toggle += ulpi_clk_period;
        }

        // Deassert reset at t = 200
        if (main_time == 200) {
            top->rst = 0;
            std::cout << "[SIM t=" << main_time << "ns] Reset deasserted (rst = 0)\n";
        }

        // Assert enable at t = 1000
        if (main_time == 1000) {
            top->enable = 1;
            std::cout << "[SIM t=" << main_time << "ns] System enabled (enable = 1)\n";
        }

        top->eval();
        tfp->dump(main_time);

        // Count bytes sent
        if (top->ulpi_clk && top->tx_valid && top->tx_ready) {
            bytes_sent++;
        }

        // Monitor tx_valid transitions
        if (top->tx_valid && !prev_tx_valid) {
            std::cout << "[SIM t=" << main_time << "ns] tx_valid ASSERTED! (Byte #" 
                      << std::dec << bytes_sent << ", sample=0x"
                      << std::hex << (int)top->tx_data << std::dec << ")\n";
        } else if (!top->tx_valid && prev_tx_valid) {
            std::cout << "[SIM t=" << main_time << "ns] tx_valid DEASSERTED! Total bytes sent so far: "
                      << std::dec << bytes_sent << "\n";
        }
        prev_tx_valid = top->tx_valid;

        main_time++;
    }

    tfp->close();
    std::cout << "[SIM] Simulation finished. Total Bytes Sent: " << std::dec << bytes_sent << "\n";
    std::cout << "[SIM] Waveform dumped to: verification/tb_adc_wrapper.vcd\n";
    return 0;
}
