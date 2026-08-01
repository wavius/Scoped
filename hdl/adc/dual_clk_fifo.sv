module dual_clk_fifo #(
  parameter int DWIDTH = 12,         // Data width
  parameter int AWIDTH = 14          // Address width | 14 = 16 kB
) (
  input  logic              a_rst,   // Asynchronous reset
  output logic              full,    // FIFO full
  output logic              empty,   // FIFO empty

  // Write signals
  input  logic              wr_clk,  // Write clock
  input  logic              wr_ena,  // Write enable
  input  logic [DWIDTH-1:0] data_in, // Data in

  // Read signals
  input  logic              rd_clk,  // Read clock
  input  logic              rd_ena,  // Read enable
  output logic [DWIDTH-1:0] data_out // Data out
);

  // Dual port dual clock RAM
  dual_port_dual_clock_ram #(DWIDTH, AWIDTH) dpdcram (
    .wr_clk  (wr_clk),
    .wr_ena  (wr_ena),
    .wr_addr (),
    .data_in (data_in),

    .rd_clk  (rd_clk),
    .rd_ena  (rd_ena),
    .rd_addr (),
    .data_out(data_out)
  );
  
endmodule
