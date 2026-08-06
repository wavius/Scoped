module top (
    input clk_25m,

    // ULPI Interface
    input        ulpi_clk60, // 60 MHz from USB3300 PHY
    inout  [7:0] ulpi_data,
    input        ulpi_dir,
    input        ulpi_nxt,
    output       ulpi_stp,
    output       ulpi_reset,

    // ADC Interface
    output logic              adc_clk_out,
    input  logic              adc_otr,
    input  logic [11:0]       adc_data_raw,

    // LEDs
    // - Active high on iCESugar-Pro
    output led_r,
    output led_g,
    output led_b
);

    // PHY reset
    wire phy_rst;
    rst_gen u_phy_rst_gen (
        .clk_i(clk_25m),
        .rst_i(1'b0),
        .rst_o(phy_rst)
    );
    assign ulpi_reset = phy_rst;

    // CDC reset
    wire cdc_rst;
    rst_gen u_cdc_rst_gen (
        .clk_i(ulpi_clk60),
        .rst_i(phy_rst),
        .rst_o(cdc_rst)
    );

    // ULPI tri-state bus
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

    // ULPI wrapper instantiation
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

    // ADC wrapper instantiation
    wire [7:0] tx_data;
    wire       tx_valid;
    wire       tx_ready;

    wire [11:0] tx_data_12b;
    assign tx_data = tx_data_12b[11:4];

    adc_wrapper u_adc_wrapper (
        .rst          (cdc_rst),
        .enable       (!cdc_rst),

        // Physical ADC pins
        .adc_clk      (clk_25m),
        .capture_en   (1'b1),
        .adc_clk_out  (adc_clk_out),
        .adc_data_raw (adc_data_raw),
        .adc_otr      (adc_otr),

        // To USB CDC (FIFO output)
        .ulpi_clk     (ulpi_clk60),
        .tx_ready     (tx_ready),
        .tx_data      (tx_data_12b),
        .tx_valid     (tx_valid)
    );

    // USB CDC core instantiation
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
    reg tx_seen = 1'b0;

    always @(posedge ulpi_clk60 or posedge cdc_rst) begin
        if (cdc_rst) begin
            tx_seen <= 1'b0;
        end else begin
            if (tx_valid && tx_ready) tx_seen <= 1'b1;
        end
    end

    assign led_r = 1'b0;      // Red OFF
    assign led_g = tx_seen;   // Green ON (1) when sine wave TX data is streaming over USB
    assign led_b = !cdc_rst;  // Blue ON (1) when USB stack is active & out of reset
endmodule
