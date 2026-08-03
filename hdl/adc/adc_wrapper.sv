module adc_wrapper #(
  parameter DWIDTH = params_pkg::DWIDTH
) (
  input  logic              rst,

  // ADC interface
  input  logic              adc_clk,
  output logic              adc_clk_out,
  input  logic [DWIDTH-1:0] adc_data_raw,
  input  logic              adc_otr,
  
  // ULPI interface
  input  logic              ulpi_clk,
  input  logic              tx_ready,
  output logic [DWIDTH-1:0] tx_data,
  output logic              tx_valid
);
  
  // ADC signals
  logic [DWIDTH-1:0] adc_data;
  logic              adc_valid; 

  // FIFO signals
  logic fifo_full, fifo_empty;
  logic fifo_rd_ena;

  assign fifo_rd_ena = tx_ready && !fifo_empty;
  assign tx_valid = !fifo_empty;

  adc_interface u_adc_int (
    .clk_25m      (adc_clk),
    .a_rst        (rst),

    .adc_data_raw (adc_data_raw),
    .adc_otr      (adc_otr),
    .adc_clk_out  (adc_clk_out),

    .sample_data  (adc_data),
    .sample_valid (adc_valid),
    .fifo_full    (fifo_full)
  );

  dual_clk_fifo u_dcfifo (
    .a_rst   (rst),
    .full    (fifo_full),
    .empty   (fifo_empty),

    .wr_clk  (adc_clk),
    .wr_ena  (adc_valid),
    .wr_data (adc_data),

    .rd_clk  (ulpi_clk),
    .rd_ena  (fifo_rd_ena),
    .rd_data (tx_data)
  );

endmodule
