`include "uart_tx.v"

module top (
    input clk_i,    // 25 MHz hardware clock
    output TX       // UART TX line
);

    parameter clk_freq = 25000000;
    parameter baudrate = 115200;

    /* UART Clock Generation */
    reg clk_uart = 0;
    reg [31:0] cntr_uart = 32'b0;
    parameter period_uart = (clk_freq / 2 / baudrate);

    /* Sample Rate Generation (e.g., 1000 samples per second) */
    reg clk_sample = 0;
    reg [31:0] cntr_sample = 32'b0;
    parameter period_sample = (clk_freq / 2 / 1000);

    /* Sine LUT and Index */
    reg [7:0] sine_rom [0:255];
    reg [7:0] phase_acc = 8'd0;
    reg [7:0] uart_txbyte;
    wire uart_txed;

    initial
    begin
        $readmemh("sine_values.mem", sine_rom);
    end

    /* UART transmitter */
    uart_tx_8n1 transmitter (
        .clk (clk_uart),
        .txbyte (uart_txbyte),
        .senddata (1'b1), // Continuous send attempt
        .txdone (uart_txed),
        .tx (TX)
    );

    /* Clock Dividers */
    always @ (posedge clk_i) begin
        // Baud Rate Clock
        if (cntr_uart == period_uart) begin
            clk_uart <= ~clk_uart;
            cntr_uart <= 0;
        end else cntr_uart <= cntr_uart + 1;

        // Sample Rate Clock
        if (cntr_sample == period_sample) begin
            clk_sample <= ~clk_sample;
            cntr_sample <= 0;
        end else cntr_sample <= cntr_sample + 1;
    end

    /* Data Logic */
    always @ (posedge clk_sample) begin
        // Move to the next point in the sine wave
        phase_acc <= phase_acc + 1;
        uart_txbyte <= sine_rom[phase_acc];
    end

endmodule
