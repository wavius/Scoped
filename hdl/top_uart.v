module top (
    input clk_25m,

    /* ADC Interface */
    output logic              adc_clk_out,
    input  logic              adc_otr,
    input  logic [11:0]       adc_data_raw,

    /* UART */
    output uart_tx,

    /* LEDs */
    output led_r,
    output led_g,
    output led_b
);

    /* Reset */
    wire rst;
    rst_gen u_rst_gen (
        .clk_i(clk_25m),
        .rst_i(1'b0),
        .rst_o(rst)
    );

    /* ADC Decimator (Capture 1 in 2500 samples to get 10 kHz from 25 MHz) */
    reg [11:0] decimate_cnt = 12'd0;
    reg capture_en = 1'b0;
    always @(posedge clk_25m) begin
        if (decimate_cnt == 12'd2499) begin
            decimate_cnt <= 12'd0;
            capture_en <= 1'b1;
        end else begin
            decimate_cnt <= decimate_cnt + 1'b1;
            capture_en <= 1'b0;
        end
    end

    /* UART Clock Generation (115200 Baud) */
    parameter clk_freq = 25000000;
    parameter baudrate = 115200;
    reg clk_uart = 0;
    reg [31:0] cntr_uart = 32'b0;
    parameter period_uart = (clk_freq / 2 / baudrate);

    always @(posedge clk_25m) begin
        if (cntr_uart == period_uart) begin
            clk_uart <= ~clk_uart;
            cntr_uart <= 0;
        end else cntr_uart <= cntr_uart + 1;
    end

    /* ADC Wrapper */
    wire [11:0] tx_data_12b;
    wire [7:0]  tx_data = tx_data_12b[11:4]; // 8 most significant bits
    wire        tx_valid;
    wire        tx_ready;

    adc_wrapper u_adc_wrapper (
        .rst          (rst),
        .enable       (!rst),

        // Physical ADC pins (Clocked directly by stable 25MHz)
        .adc_clk      (clk_25m),
        .capture_en   (capture_en),
        .adc_clk_out  (adc_clk_out),
        .adc_data_raw (adc_data_raw),
        .adc_otr      (adc_otr),

        // To UART (FIFO output)
        .ulpi_clk     (clk_uart),
        .tx_ready     (tx_ready),
        .tx_data      (tx_data_12b),
        .tx_valid     (tx_valid)
    );

    /* UART Transmitter state */
    wire uart_txed;
    reg  uart_busy = 1'b0;

    always @(posedge clk_uart) begin
        if (rst) begin
            uart_busy <= 1'b0;
        end else begin
            if (tx_valid && !uart_busy) begin
                uart_busy <= 1'b1;
            end else if (uart_txed) begin
                uart_busy <= 1'b0;
            end
        end
    end

    assign tx_ready = !uart_busy;
    wire senddata = tx_valid && !uart_busy;

    /* UART Transmitter Module */
    uart_tx_8n1 u_uart_tx (
        .clk      (clk_uart),
        .txbyte   (tx_data),
        .senddata (senddata),
        .txdone   (uart_txed),
        .tx       (uart_tx)
    );

    /* LEDs (Active-HIGH on iCESugar-Pro: 1 = ON, 0 = OFF) */
    assign led_r = 1'b0;
    assign led_g = 1'b0;
    assign led_b = !rst; // Health indicator

endmodule
