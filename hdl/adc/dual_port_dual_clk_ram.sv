//=============================================================================
// Module: dual_port_dual_clock_ram
// Description: Dual port dual clock BRAM.
//=============================================================================
`default_nettype none

module dual_port_dual_clk_ram 
  import params_pkg::*; 
(
  // Write signals
  input  logic              wr_clk,  // Write clock 
  input  logic              wr_ena,  // Write enable
  input  logic [AWIDTH-1:0] wr_addr, // Write address
  input  logic [DWIDTH-1:0] wr_data, // Write data

  // Read signals
  input  logic              rd_clk,  // Read clock
  input  logic              rd_ena,  // Read enable
  input  logic [AWIDTH-1:0] rd_addr, // Read address
  output logic [DWIDTH-1:0] rd_data  // Read data
);

  localparam int MDEPTH = 2**AWIDTH; // Memory depth

  logic [DWIDTH-1:0] mem [0:MDEPTH-1];

  always_ff @(posedge wr_clk) begin
    if (wr_ena) begin
      mem[wr_addr] <= wr_data;
    end
  end

  always_ff @(posedge rd_clk) begin
    if (rd_ena) begin
      rd_data <= mem[rd_addr];
    end
  end

endmodule

