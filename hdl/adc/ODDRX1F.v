`ifndef SYNTHESIS
module ODDRX1F (
  input  wire D0,
  input  wire D1,
  input  wire SCLK,
  input  wire RST,
  output reg Q
);
  wire _unused = D1;

  always_ff@(posedge SCLK, posedge RST) begin
    if (RST) Q <= 1'b0;
    else Q <= D0;
  end
endmodule
`endif
