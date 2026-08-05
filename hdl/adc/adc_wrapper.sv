module adc_wrapper #(
  parameter DWIDTH = params_pkg::DWIDTH,
  parameter AWIDTH = params_pkg::AWIDTH
) (
  input  logic              rst,
  input  logic              enable,

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
  logic              fifo_full, fifo_empty;
  logic              fifo_rd_ena;
  logic [AWIDTH:0]   fifo_count;

  // 2FF Reset Synchronizer for 25 MHz ADC clock domain
  logic adc_rst_ms, adc_rst_sync;
  always_ff @(posedge adc_clk or posedge rst) begin
    if (rst) begin
      adc_rst_ms   <= 1'b1;
      adc_rst_sync <= 1'b1;
    end else begin
      adc_rst_ms   <= 1'b0;
      adc_rst_sync <= adc_rst_ms;
    end
  end

  adc_interface u_adc_int (
    .clk_25m      (adc_clk),
    .a_rst        (adc_rst_sync),

    .adc_data_raw (adc_data_raw),
    .adc_otr      (adc_otr),
    .adc_clk_out  (adc_clk_out),

    .sample_data  (adc_data),
    .sample_valid (adc_valid),
    .fifo_full    (fifo_full)
  );

  fwft_dual_clk_fifo u_dc_fifo (
    .a_rst   (rst),
 
    .wr_clk  (adc_clk),
    .wr_ena  (adc_valid),
    .wr_data (adc_data),
    .full    (fifo_full),

    .rd_clk  (ulpi_clk),
    .rd_ena  (fifo_rd_ena),
    .rd_data (tx_data),
    .empty   (fifo_empty),
    .count   (fifo_count)
  );

  typedef enum logic { IDLE, BURST } state_t;
  state_t current_state, next_state;
  
  // Combinational to fetch next FIFO sample 1 cycle early
  assign fifo_rd_ena = (current_state == BURST) && tx_ready && !fifo_empty;

  logic [9:0] burst_count;
  logic       byte_sent;
  assign byte_sent = tx_ready && tx_valid;

  always_ff @(posedge ulpi_clk or posedge rst) begin
    if (rst) begin
      burst_count   <= '0;
          tx_valid  <= 0;
      current_state <= IDLE;
    end 
    else if (!enable) begin
      burst_count   <= '0;
          tx_valid  <= 0;
      current_state <= IDLE;
    end
    else begin
      current_state <= next_state;
      case (current_state) 
        IDLE: begin
          burst_count <= '0;
          tx_valid    <= 0;
        end
        // Send 512 kB packet over ULPI
        BURST: begin
          if (next_state == IDLE) begin
            tx_valid <= 0; 
          end 
          else begin
            tx_valid <= !fifo_empty && enable;
          end
          if (byte_sent)
            burst_count <= burst_count + 10'b1;
        end
      endcase
    end
  end

  always_comb begin
    next_state = current_state;
    case (current_state)
      IDLE: begin
        if (fifo_count >= 15'd511) next_state = BURST;
      end
      BURST: begin
        if ((burst_count == 10'd511) && byte_sent) next_state = IDLE;
      end
    endcase
  end

endmodule
