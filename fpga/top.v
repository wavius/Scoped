module top (
    input clk_25m,

    // ULPI Interface
    input        ulpi_clk60, // 60 MHz from USB3300 PHY
    inout  [7:0] ulpi_data,
    input        ulpi_dir,
    input        ulpi_nxt,
    output       ulpi_stp,
    output       ulpi_reset,

    // LEDs (Active-HIGH on iCESugar-Pro: 1 = ON, 0 = OFF)
    output led_r,
    output led_g,
    output led_b
);

    // ========================================================
    // 1. PHY Hardware Reset Generator (25 MHz Onboard Clock)
    // ========================================================
    // Waveshare USB3300 RESET pin is Active-HIGH.
    // Hold HIGH (1) for ~10ms at boot, then drive LOW (0) for normal operation.
    reg [19:0] rst_cnt = 20'd0;
    reg        phy_rst = 1'b1; // Active-High Reset

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

    // ========================================================
    // 2. Async Assert, Sync Deassert Reset Synchronizer for 60MHz
    // ========================================================
    reg [2:0] rst_sync = 3'b111;
    always @(posedge ulpi_clk60 or posedge phy_rst) begin
        if (phy_rst) begin
            rst_sync <= 3'b111;
        end else begin
            rst_sync <= {rst_sync[1:0], 1'b0};
        end
    end
    wire cdc_rst = rst_sync[2]; // Active-High internal logic reset

    // Ignore startup transient glitches for ~100ms after reset
    reg [22:0] startup_timer = 23'd0;
    reg        ready_for_leds = 1'b0;
    always @(posedge ulpi_clk60 or posedge cdc_rst) begin
        if (cdc_rst) begin
            startup_timer  <= 23'd0;
            ready_for_leds <= 1'b0;
        end else if (!ready_for_leds) begin
            if (startup_timer < 23'd6_000_000) begin // 100ms at 60MHz
                startup_timer <= startup_timer + 1'b1;
            end else begin
                ready_for_leds <= 1'b1;
            end
        end
    end

    // ========================================================
    // 3. ULPI Tri-State Bus
    // ========================================================
    wire [7:0] ulpi_data_in  = ulpi_data;
    wire [7:0] ulpi_data_out;

    assign ulpi_data = (!ulpi_dir) ? ulpi_data_out : 8'hzz;

    // ========================================================
    // 4. UTMI Signals between ULPI Wrapper and USB CDC Core
    // ========================================================
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

    // ========================================================
    // 5. ULPI Wrapper Instantiation
    // ========================================================
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

    // ========================================================
    // 6. Loopback Stream Logic (128-byte Synchronous FIFO)
    // ========================================================
    wire [7:0] rx_data;
    wire       rx_valid;
    wire       rx_ready;

    wire [7:0] tx_data;
    wire       tx_valid;
    wire       tx_ready;

    reg [7:0] fifo_mem [0:127];
    reg [6:0] fifo_waddr;
    reg [6:0] fifo_raddr;
    reg [7:0] fifo_count;

    wire fifo_full  = (fifo_count == 8'd128);
    wire fifo_empty = (fifo_count == 8'd0);

    // Write logic (from RX)
    always @(posedge ulpi_clk60 or posedge cdc_rst) begin
        if (cdc_rst) begin
            fifo_waddr <= 7'd0;
        end else if (!ready_for_leds) begin
            fifo_waddr <= 7'd0;
        end else if (rx_valid && !fifo_full) begin
            fifo_mem[fifo_waddr] <= rx_data;
            fifo_waddr <= fifo_waddr + 1'b1;
        end
    end

    // Read logic (to TX) and Count management
    always @(posedge ulpi_clk60 or posedge cdc_rst) begin
        if (cdc_rst) begin
            fifo_raddr <= 7'd0;
            fifo_count <= 8'd0;
        end else if (!ready_for_leds) begin
            fifo_raddr <= 7'd0;
            fifo_count <= 8'd0;
        end else begin
            case ({ (rx_valid && !fifo_full), (tx_valid && tx_ready) })
                2'b10: fifo_count <= fifo_count + 1'b1;
                2'b01: begin
                    fifo_count <= fifo_count - 1'b1;
                    fifo_raddr <= fifo_raddr + 1'b1;
                end
                2'b11: begin
                    fifo_raddr <= fifo_raddr + 1'b1;
                end
                default: ;
            endcase
        end
    end

    assign rx_ready = !fifo_full && ready_for_leds;
    assign tx_data  = fifo_mem[fifo_raddr];
    assign tx_valid = !fifo_empty && ready_for_leds;

    // ========================================================
    // 7. USB CDC Core Instantiation
    // ========================================================
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

        .outport_accept_i   (rx_ready),
        .outport_valid_o    (rx_valid),
        .outport_data_o     (rx_data),

        .utmi_data_out_o    (utmi_data_out_wrapper),
        .utmi_txvalid_o     (utmi_txvalid_core),
        .utmi_op_mode_o     (utmi_op_mode_core),
        .utmi_xcvrselect_o  (utmi_xcvrselect_core),
        .utmi_termselect_o  (utmi_termselect_core),
        .utmi_dppulldown_o  (utmi_dppulldown_core),
        .utmi_dmpulldown_o  (utmi_dmpulldown_core)
    );

    // ========================================================
    // 8. LED Indicators (Active-HIGH: 1 = ON, 0 = OFF)
    // ========================================================
    reg rx_seen = 1'b0;
    reg tx_seen = 1'b0;

    always @(posedge ulpi_clk60 or posedge cdc_rst) begin
        if (cdc_rst) begin
            rx_seen <= 1'b0;
            tx_seen <= 1'b0;
        end else if (ready_for_leds) begin
            if (rx_valid && rx_ready) rx_seen <= 1'b1;
            if (tx_valid && tx_ready) tx_seen <= 1'b1;
        end
    end

    assign led_r = rx_seen;   // Red ON (1) when valid RX data seen post-boot
    assign led_g = tx_seen;   // Green ON (1) when valid TX data seen post-boot
    assign led_b = !cdc_rst;  // Blue ON (1) when USB stack is active & out of reset
endmodule
