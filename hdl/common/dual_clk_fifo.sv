//=============================================================================
// Module: dual_clk_fifo
// Description: Asynchronous dual clock FIFO.
//=============================================================================
`default_nettype none

module dual_clk_fifo #(
  parameter AWIDTH = params_pkg::AWIDTH,
  parameter DWIDTH = params_pkg::DWIDTH
) (
  input  logic              a_rst,   // Asynchronous reset

  // Write domain
  input  logic              wr_clk,  // Write clock
  input  logic              wr_ena,  // Write enable
  input  logic [DWIDTH-1:0] wr_data, // Write data
  output logic              full,    // FIFO full

  // Read domain
  input  logic              rd_clk,  // Read clock
  input  logic              rd_ena,  // Read enable
  output logic [DWIDTH-1:0] rd_data, // Read data
  output logic              empty,   // FIFO empty
  output logic [AWIDTH:0]   count    // Number of samples in FIFO (0 to 2^AWIDTH)
);
  localparam int PTR_WIDTH = AWIDTH + 1;

  // Reset
  logic wr_a_rst, wr_a_rst_ms; // Write reset, metastable write reset
  logic rd_a_rst, rd_a_rst_ms; // Read reset, metastable read reset

  // 2FF synchronizers
  // - Async-assert, sync-deassert
  always_ff @(posedge wr_clk or posedge a_rst) begin
    if (a_rst) begin
      wr_a_rst_ms <= 1'b1;
      wr_a_rst    <= 1'b1;
    end
    else begin
      wr_a_rst_ms <= 1'b0;
      wr_a_rst    <= wr_a_rst_ms;
    end
  end

  always_ff @(posedge rd_clk or posedge a_rst) begin
    if (a_rst) begin
      rd_a_rst_ms <= 1'b1;
      rd_a_rst    <= 1'b1;
    end
    else begin
      rd_a_rst_ms <= 1'b0;
      rd_a_rst    <= rd_a_rst_ms;
    end
  end


  // Read and write pointers
  // - MSB is full/empty bit
  logic [PTR_WIDTH-1:0] wr_ptr, wr_ptr_gray;       // Write pointer, gray write pointer
  logic [PTR_WIDTH-1:0] wr_ptr_ms;                 // Metastable write pointer                              
  logic [PTR_WIDTH-1:0] wr_ptr_rd, wr_ptr_gray_rd; // Read domain write pointer, gray read domain write pointer
  
  logic [PTR_WIDTH-1:0] rd_ptr, rd_ptr_gray;       // Read pointer, gray read pointer
  logic [PTR_WIDTH-1:0] rd_ptr_ms;                 // Metastable read pointer
  logic [PTR_WIDTH-1:0] rd_ptr_wr, rd_ptr_gray_wr; // Write domain read pointer, gray write domain read pointer
  
  // Increment read and write pointers
  always_ff @(posedge wr_clk or posedge wr_a_rst) begin
    if (wr_a_rst) begin
      wr_ptr <= {PTR_WIDTH{1'b0}};
    end
    else if (wr_ena) begin
      wr_ptr <= wr_ptr + 1;
    end
  end

  always_ff @(posedge rd_clk or posedge rd_a_rst) begin
    if (rd_a_rst) begin
      rd_ptr <= {PTR_WIDTH{1'b0}};
    end
    else if (rd_ena) begin
      rd_ptr <= rd_ptr + 1;
    end
  end


  // Gray pointers
  // - Consecutive values differ by exactly 1 bit
  assign wr_ptr_gray = utils_pkg::bin2gray(wr_ptr);
  assign rd_ptr_gray = utils_pkg::bin2gray(rd_ptr);

  // 2FF synchronizers
  always_ff @(posedge rd_clk) begin
    wr_ptr_ms      <= wr_ptr_gray;
    wr_ptr_gray_rd <= wr_ptr_ms;
  end

  always_ff @(posedge wr_clk) begin
    rd_ptr_ms      <= rd_ptr_gray;
    rd_ptr_gray_wr <= rd_ptr_ms;
  end                                        

  // FIFO full and empty (gray)
  assign empty = (rd_ptr_gray == wr_ptr_gray_rd);
  assign full  = (wr_ptr_gray == {~rd_ptr_gray_wr[AWIDTH:AWIDTH-1], rd_ptr_gray_wr[AWIDTH-2:0]});
  

  // Opposite clock domain binary pointers
  assign wr_ptr_rd = utils_pkg::gray2bin(wr_ptr_gray_rd);
  assign rd_ptr_wr = utils_pkg::gray2bin(rd_ptr_gray_wr);
  
  // FIFO count
  assign count = wr_ptr_rd - rd_ptr;

  // FIFO full and empty (binary)
  // assign empty = (rd_ptr == wr_ptr_rd);
  // assign full  = (wr_ptr == {~rd_ptr_wr[AWIDTH], rd_ptr_wr[AWIDTH-1:0]});


  // Dual port dual clock RAM
  dual_port_dual_clk_ram u_dpdcram (
    .wr_clk  (wr_clk),
    .wr_ena  (wr_ena),
    .wr_addr (wr_ptr[AWIDTH-1:0]),
    .wr_data (wr_data),

    .rd_clk  (rd_clk),
    .rd_ena  (rd_ena),
    .rd_addr (rd_ptr[AWIDTH-1:0]),
    .rd_data (rd_data)
  );
  
endmodule
