//=============================================================================
// Package: utils_pkg 
// Description: Package containing utility functions.
//=============================================================================
`default_nettype none

package utils_pkg;
  import params_pkg::*;
  
  function automatic logic [AWIDTH:0] bin2gray (
    input logic [AWIDTH:0] bin
  );
    return bin ^ (bin >> 1);
  endfunction

  function automatic logic [AWIDTH:0] gray2bin (
    input logic [AWIDTH:0] gray
  );
    localparam int WIDTH = AWIDTH + 1;
    logic [WIDTH-1:0] bin = gray;
    
    for (int i = 1; i < WIDTH; i = i << 1) begin
      bin = bin ^ (bin >> i);
    end
    
    return bin;
  endfunction

endpackage
