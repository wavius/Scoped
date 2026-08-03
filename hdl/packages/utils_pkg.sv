//=============================================================================
// Package: utils_pkg 
// Description: Package containing utility functions.
//=============================================================================
`default_nettype none

package utils_pkg;
  function [params_pkg::AWIDTH:0] bin2gray;
    input [params_pkg::AWIDTH:0] bin;
    begin
      bin2gray = bin ^ (bin >> 1);
    end
  endfunction

  function [params_pkg::AWIDTH:0] gray2bin;
    input [params_pkg::AWIDTH:0] gray;
    integer i;
    reg [params_pkg::AWIDTH:0] b;
    begin
      b = gray;
      for (i = 1; i <= params_pkg::AWIDTH; i = i << 1) begin
        b = b ^ (b >> i);
      end
      gray2bin = b;
    end
  endfunction
endpackage
