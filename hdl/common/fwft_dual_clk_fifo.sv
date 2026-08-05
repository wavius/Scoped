//=============================================================================                                                                                                                               
// Module: fwft_dual_clk_fifo                                                                                                                                                                                 
// Description: First-Word Fall-Through (FWFT) Dual-Clock FIFO Wrapper.                                                                                                                                       
//============================================================================= 
`default_nettype none

module fwft_dual_clk_fifo #(
  parameter AWIDTH = params_pkg::AWIDTH,
  parameter DWIDTH = params_pkg::DWIDTH
) (
  input  logic              a_rst,                                                                                                                                                                            
                                                                                                                                                                                                                  
  // Write domain                                                                                                                                                                                 
  input  logic              wr_clk,                                                                                                                                                                           
  input  logic              wr_ena,                                                                                                                                                                           
  input  logic [DWIDTH-1:0] wr_data,                                                                                                                                                                          
  output logic              full,                                                                                                                                                                             
                                                                                                                                                                                                                  
  // Read domain                                                                                                                                                                                     
  input  logic              rd_clk,                                                                                                                                                                           
  input  logic              rd_ena,  // Pop current word                                                                                                                                                     
  output logic [DWIDTH-1:0] rd_data, // Valid IMMEDIATELY when empty == 0                                                                                                                                    
  output logic              empty,   // 0 = valid data present at rd_data
  output logic [AWIDTH:0]   count    // Number of samples in FIFO
);

  // Standard FIFO signals
  logic              std_empty;
  logic              std_rd_ena;
  logic [DWIDTH-1:0] std_rd_data;
  logic [AWIDTH:0]   std_count;

  dual_clk_fifo #(                                                                                                                                                                                            
    .AWIDTH(AWIDTH),                                                                                                                                                                                          
    .DWIDTH(DWIDTH)                                                                                                                                                                                           
  ) u_std_dc_fifo (                                                                                                                                                                                              
    .a_rst   (a_rst),                                                                                                                                                                                         

    .wr_clk  (wr_clk),                                                                                                                                                                                        
    .wr_ena  (wr_ena),                                                                                                                                                                                        
    .wr_data (wr_data),   
    .full    (full),                                                                                                                                                                                          

    .rd_clk  (rd_clk),                                                                                                                                                                                        
    .rd_ena  (std_rd_ena),                                                                                                                                                                                    
    .rd_data (std_rd_data),                                                                                                                                                                                   
    .empty   (std_empty),     
    .count   (std_count)
  );

  logic data_out_valid;
  logic fall_through;
  logic middle_valid;
  logic [DWIDTH-1:0] middle_data;

  assign empty = !data_out_valid;
  assign count = std_count + data_out_valid + middle_valid + fall_through;

  // Request data if underlying FIFO isn't empty AND (current output registers are not fully filled
  // or downstream read request)
  assign std_rd_ena = !std_empty && (!data_out_valid || !middle_valid || rd_ena);

  always_ff @(posedge rd_clk or posedge a_rst) begin
    if (a_rst) begin
      data_out_valid <= 1'b0;
      middle_valid   <= 1'b0;
      fall_through   <= 1'b0;
      rd_data        <= '0;
      middle_data    <= '0;
    end
    else begin
      fall_through <= std_rd_ena;

      if (rd_ena && data_out_valid) begin
        if (middle_valid) begin
          rd_data        <= middle_data;
          middle_valid   <= 1'b0;
          data_out_valid <= 1'b1;

          if (fall_through) begin
            middle_data  <= std_rd_data;
            middle_valid <= 1'b1;
          end
        end else if (fall_through) begin
          rd_data        <= std_rd_data;
          data_out_valid <= 1'b1;
        end else begin
          data_out_valid <= 1'b0;
        end
      end else begin
        if (!data_out_valid && fall_through) begin
          rd_data        <= std_rd_data;
          data_out_valid <= 1'b1;
        end else if (data_out_valid && fall_through && !middle_valid) begin
          middle_data  <= std_rd_data;
          middle_valid <= 1'b1;
        end
      end
    end
  end

endmodule
