module top (
    input clk_25m,

    /* ADC interface */
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

    /* ADC decimator (capture 1 in 100 samples to get 250 kHz from 25 MHz) */
    reg [11:0] decimate_cnt = 12'd0;
    reg capture_en = 1'b0;
    always @(posedge clk_25m) begin
        if (decimate_cnt == 12'd99) begin
            decimate_cnt <= 12'd0;
            capture_en <= 1'b1;
        end else begin
            decimate_cnt <= decimate_cnt + 1'b1;
            capture_en <= 1'b0;
        end
    end

    /* UART clock generation (1 MBaud) */
    parameter clk_freq = 25000000;
    parameter baudrate = 1000000;
    reg clk_uart = 0;
    reg [31:0] cntr_uart = 32'b0;
    parameter period_uart = (clk_freq / 2 / baudrate);

    always @(posedge clk_25m) begin
        if (cntr_uart + baudrate >= (clk_freq / 2)) begin
            clk_uart <= ~clk_uart;
            cntr_uart <= cntr_uart + baudrate - (clk_freq / 2);
        end else begin
            cntr_uart <= cntr_uart + baudrate;
        end
    end

    /* ADC wrapper */
    wire [11:0] tx_data_12b;
    wire [7:0]  tx_data = tx_data_12b[11:4]; // 8 MSBs
    wire        tx_valid;
    wire        tx_ready;

    adc_wrapper #(
        .CTYPE(types_pkg::UART)
    ) u_adc_wrapper (
        .rst          (rst),
        .enable       (!rst),
 
        // ADC interface
        .adc_clk      (clk_25m),
        .capture_en   (capture_en),
        .adc_clk_out  (adc_clk_out),
        .adc_data_raw (adc_data_raw),
        .adc_otr      (adc_otr),

        // UART interface
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

    /* LEDs */
    assign led_r = 1'b0;
    assign led_g = 1'b0;
    assign led_b = !rst; // Health indicator

endmodule
