module dual_port_dual_clock_ram #(
  parameter int DWIDTH = 12,
  parameter int AWIDTH = 14
) ( 
  // Write signals
  input  logic              wr_clk,  // Write clock 
  input  logic              wr_ena,  // Write enable
  input  logic [AWIDTH-1:0] wr_addr, // Write address
  input  logic [DWIDTH-1:0] data_in, // Write data

  // Read signals
  input  logic              rd_clk,  // Read clock
  input  logic              rd_ena,  // Read enable
  input  logic [AWIDTH-1:0] rd_addr, // Read address
  output logic [DWIDTH-1:0] data_out // Read data
);
  localparam MDEPTH = 2**AWIDTH;     // Memory depth

  logic [DWIDTH-1:0] mem [0:MDEPTH-1];

  always_ff @(posedge wr_clk) begin
    if (wr_ena) begin
      mem[wr_addr] <= data_in;
    end
  end

  always_ff @(posedge rd_clk) begin
    if (rd_ena) begin
      data_out <= mem[rd_addr];
    end
  end

endmodule
