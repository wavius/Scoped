//=============================================================================
// Module: adc_interface
// Description: Interfaces the AD9226 ADC. Generates a 25MHz clock for the ADC. Collects 12-bit ADC samples
//              in an asynchronous FIFO.
//              
//=============================================================================
`default_nettype none

module adc_interface (
  input  logic clk_25m,             // 25 MHz input clock domain
  input  logic a_rst,               // Asynchronous reset
  
  // AD9226 pins
  input  logic [11:0] adc_data_raw, // 12-bit data
  input  logic        adc_otr,      // Out-of-range indicator | UNUSED
  output logic        adc_clk_out,  // Clock pin output | MAX 65 MHz | CURRENT: 25 MHz

  // Asynchronous FIFO
  output logic [11:0]  sample_data, // Data to push into FIFO
  output logic        sample_valid, // Write_enable for FIFO
  input  logic        fifo_full     // Full flag
  );
  
  // AD9226 25 Mhz clock
  // ODDR: Output double data rate
  // X1: 1:1 gear ratio
  // F: flip-flop
  // - Low clock jitter
  // - Phase alignment with interal signals
  ODDRX1F u_oddr (
    .D0(1'b1),
    .D1(1'b0),
    .SCLK(clk_25m),
    .RST(a_rst),
    .Q(adc_clk_out)
    );
  

  // AD9226 7-cycle startup latency counter
  logic [2:0] latency_counter;
  logic       adc_ready;
  assign adc_ready = (latency_counter == 3'd0);

  // AD9226 valid sample
  assign sample_valid = (adc_ready && !fifo_full);

  always_ff @(posedge clk_25m or posedge a_rst) begin
    if (a_rst) begin
      latency_counter <= 3'd7;
      sample_data     <= 0;
    end
    // Wait 7 clock cycles for valid pipeline data from AD9226
    else if (!adc_ready) begin
      latency_counter <= latency_counter - 3'b1;
      sample_data     <= 0;
    end
    // Stream valid ADC samples into FIFO when ready and not full
    else begin
      latency_counter <= 0;
      sample_data     <= adc_data_raw;
    end
  end

endmodule

