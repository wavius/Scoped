
//=============================================================================
// Module: adc_interface
// Description: Interfaces the AD9226 ADC. Generates a 25MHz clock for the ADC. Collects 12-bit ADC samples
//              in an asynchronous FIFO.
//              
//=============================================================================
`default_nettype none

module adc_interface (
  input wire clk_25m,              // 25 MHz input clock domain
  input wire rst,                  // Asynchronous reset
  
  // AD9226 pins
  input  wire [11:0] adc_data_raw, // 12-bit data
  input  wire        adc_otr,      // Out-of-range indicator
  output wire        adc_clk_out,  // Clock pin output | MAX 65 MHz | CURRENT: 25 MHz

  // Asynchronous FIFO
  output reg [11:0]  sample_data,  // Data to push into FIFO
  output reg         sample_valid, // Write_enable for FIFO
  input  wire        fifo_full     // Full flag
  );
  
  // Output double data rate register 
  // X1: 1:1 gear ratio
  // F: flip-flop
  // - Low clock jitter
  // - Phase alignment with interal signals
  ODDRX1F u_oddr (
    .D0(1'b1),
    .D1(1'b0),
    .SCLK(clk_25m),
    .RST(rst),
    .Q(adc_clk_out)
    );

endmodule

