//=============================================================================
// Module: top
// Description: Top-level module integrating USB CDC core, ULPI wrapper,
//              and AD9226 ADC interface for Scoped oscilloscope FPGA.
//=============================================================================
`default_nettype none

module top (
    input clk_25m,

    // ULPI interface
    input        ulpi_clk60, // 60 MHz from USB3300 PHY
    inout  [7:0] ulpi_data,
    input        ulpi_dir,
    input        ulpi_nxt,
    output       ulpi_stp,
    output       ulpi_reset,

    // AD9226 ADC interface
    output        adc_clk_out,
    input  [11:0] adc_data_raw,
    input         adc_otr,

    // LEDs 
    // - Active HIGH
    output led_r,
    output led_g,
    output led_b
);

  // PHY Hardware Reset Generator (25 MHz Onboard Clock)
  // - Waveshare USB3300 RESET pin is Active-HIGH
  // - Hold HIGH for ~10ms at boot, then drive LOW for normal operation
  reg [19:0] rst_cnt;
  reg        phy_rst;

  always @(posedge clk_25m) begin
    if (rst_cnt < 20'd250_000) begin // 10ms at 25MHz
      rst_cnt <= rst_cnt + 1'b1;
      phy_rst <= 1'b1; // Hold PHY in reset
    end else begin
      phy_rst <= 1'b0; // Release reset (Normal operation)
      rst_cnt <= 20'd250_000; // Lock counter to prevent rollover
    end
  end

  assign ulpi_reset = phy_rst;

  // Async Assert, Sync Deassert Reset Synchronizer for 60 MHz clock domain
  reg rst_sync, rst_sync_ms;
  always @(posedge ulpi_clk60 or posedge phy_rst) begin
    if (phy_rst) begin
      rst_sync_ms <= 1;
      rst_sync    <= 1;
    end else begin
      rst_sync_ms <= 0;
      rst_sync    <= rst_sync_ms;
    end
  end
  wire cdc_rst = rst_sync; // Active-High internal logic reset

  // Wait for USB enumeration and ignore startup transience
  reg [22:0] startup_timer;
  reg        ready; // 
  always @(posedge ulpi_clk60 or posedge cdc_rst) begin
    if (cdc_rst) begin
      startup_timer  <= 23'd0;
      ready          <= 1'b0;
    end else if (!ready) begin
      if (startup_timer < 23'd6_000_000) begin // 100ms at 60MHz
        startup_timer <= startup_timer + 1'b1;
      end else begin
        ready <= 1'b1;
      end
    end
  end

  // ULPI Tri-State Bus
  wire [7:0] ulpi_data_in  = ulpi_data;
  wire [7:0] ulpi_data_out;

  assign ulpi_data = (!ulpi_dir) ? ulpi_data_out : 8'hzz;

  // UTMI signals between ULPI wrapper and USB CDC core
  wire [7:0] utmi_data_out_wrapper;
  wire [7:0] utmi_data_in_wrapper;
  wire       utmi_txvalid_core;
  wire       utmi_txready_wrapper;
  wire       utmi_rxvalid_wrapper;
  wire       utmi_rxactive_wrapper;
  wire       utmi_rxerror_wrapper;
  wire [1:0] utmi_linestate_wrapper;
  wire [1:0] utmi_op_mode_core;
  wire [1:0] utmi_xcvrselect_core;
  wire       utmi_termselect_core;
  wire       utmi_dppulldown_core;
  wire       utmi_dmpulldown_core;

  // ULPI wrapper 
  ulpi_wrapper u_ulpi (
    .ulpi_clk60_i       (ulpi_clk60),
    .ulpi_rst_i         (cdc_rst),
    .ulpi_data_out_i    (ulpi_data_in),
    .ulpi_dir_i         (ulpi_dir),
    .ulpi_nxt_i         (ulpi_nxt),
    .utmi_data_out_i    (utmi_data_out_wrapper),
    .utmi_txvalid_i     (utmi_txvalid_core),
    .utmi_op_mode_i     (utmi_op_mode_core),
    .utmi_xcvrselect_i  (utmi_xcvrselect_core),
    .utmi_termselect_i  (utmi_termselect_core),
    .utmi_dppulldown_i  (utmi_dppulldown_core),
    .utmi_dmpulldown_i  (utmi_dmpulldown_core),

    .ulpi_data_in_o     (ulpi_data_out),
    .ulpi_stp_o         (ulpi_stp),
    .utmi_data_in_o     (utmi_data_in_wrapper),
    .utmi_txready_o     (utmi_txready_wrapper),
    .utmi_rxvalid_o     (utmi_rxvalid_wrapper),
    .utmi_rxactive_o    (utmi_rxactive_wrapper),
    .utmi_rxerror_o     (utmi_rxerror_wrapper),
    .utmi_linestate_o   (utmi_linestate_wrapper)
  );

  // ADC wrapper 
  wire [7:0]  tx_data;
  wire [11:0] tx_data_12b;
  wire        tx_valid;
  wire        tx_ready;

  assign tx_data = tx_data_12b[11:4];

  adc_wrapper u_adc_wrap (
    .rst          (cdc_rst),
    .enable       (ready),

    .adc_clk      (clk_25m),
    .adc_clk_out  (adc_clk_out),
    .adc_data_raw (adc_data_raw),
    .adc_otr      (adc_otr),

    .ulpi_clk     (ulpi_clk60),
    .tx_ready     (tx_ready),
    .tx_data      (tx_data_12b),
    .tx_valid     (tx_valid)
  );

  // USB CDC core
  usb_cdc_core #(
    .USB_SPEED_HS("True")
  ) u_cdc (
    .clk_i              (ulpi_clk60),
    .rst_i              (cdc_rst),
    .enable_i           (1'b1),
    .utmi_data_in_i     (utmi_data_in_wrapper),
    .utmi_txready_i     (utmi_txready_wrapper),
    .utmi_rxvalid_i     (utmi_rxvalid_wrapper),
    .utmi_rxactive_i    (utmi_rxactive_wrapper),
    .utmi_rxerror_i     (utmi_rxerror_wrapper),
    .utmi_linestate_i   (utmi_linestate_wrapper),

    .inport_valid_i     (tx_valid),
    .inport_data_i      (tx_data),
    .inport_accept_o    (tx_ready),

    .outport_accept_i   (1'b1),
    .outport_valid_o    (),
    .outport_data_o     (),

    .utmi_data_out_o    (utmi_data_out_wrapper),
    .utmi_txvalid_o     (utmi_txvalid_core),
    .utmi_op_mode_o     (utmi_op_mode_core),
    .utmi_xcvrselect_o  (utmi_xcvrselect_core),
    .utmi_termselect_o  (utmi_termselect_core),
    .utmi_dppulldown_o  (utmi_dppulldown_core),
    .utmi_dmpulldown_o  (utmi_dmpulldown_core)
  );

  // LED indicators 
  reg tx_seen;

  always @(posedge ulpi_clk60 or posedge cdc_rst) begin
    if (cdc_rst) begin
      tx_seen <= 1'b0;
    end else if (ready) begin
      if (tx_valid && tx_ready) tx_seen <= 1'b1;
    end
  end

  assign led_r = 1'b0;     // Red OFF
  assign led_g = tx_seen;  // Green ON (1) when TX data is streaming over USB
  assign led_b = !cdc_rst; // Blue ON (1) when USB stack is active & out of reset
endmodule
