//=============================================================================
// Module: sine_gen
// Description: Test signal generator for Scoped FPGA USB transmission.
//              Generates an 8-bit digital sine wave (centered at 128)
//              and streams bytes over an AXI-Stream-style valid/ready interface.
//=============================================================================
`default_nettype none

module sine_gen (
    input  wire       clk,         // 60MHz ULPI clock (ulpi_clk60)
    input  wire       rst,         // System reset (cdc_rst)
    input  wire       enable,      // Enable signal (high when USB is enumerated)
    input  wire       tx_ready,    // USB TX stream ready input
    output reg  [7:0] sample_data, // 8-bit sample output (0 to 255)
    output wire       sample_valid // 1 = valid sample available to transmit
);

    // 16-bit DDS Phase Accumulator
    // Increments phase whenever tx_ready accepts a byte sample
    reg [15:0] phase_acc;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            phase_acc <= 16'd0;
        end else if (enable) begin
            if (tx_ready) begin
                phase_acc <= phase_acc + 16'd1000; // ~65.5 samples per sine period
            end
        end else begin
            phase_acc <= 16'd0;
        end
    end

    wire [7:0] phase = phase_acc[15:8];

    // 256-entry 8-bit Sine ROM lookup table (centered at 128)
    reg [7:0] sine_rom [0:255];

    initial begin
        sine_rom[  0] = 8'd128; sine_rom[  1] = 8'd131; sine_rom[  2] = 8'd134; sine_rom[  3] = 8'd137;
        sine_rom[  4] = 8'd140; sine_rom[  5] = 8'd143; sine_rom[  6] = 8'd146; sine_rom[  7] = 8'd149;
        sine_rom[  8] = 8'd152; sine_rom[  9] = 8'd155; sine_rom[ 10] = 8'd158; sine_rom[ 11] = 8'd161;
        sine_rom[ 12] = 8'd164; sine_rom[ 13] = 8'd167; sine_rom[ 14] = 8'd170; sine_rom[ 15] = 8'd173;
        sine_rom[ 16] = 8'd176; sine_rom[ 17] = 8'd178; sine_rom[ 18] = 8'd181; sine_rom[ 19] = 8'd184;
        sine_rom[ 20] = 8'd187; sine_rom[ 21] = 8'd189; sine_rom[ 22] = 8'd192; sine_rom[ 23] = 8'd194;
        sine_rom[ 24] = 8'd197; sine_rom[ 25] = 8'd199; sine_rom[ 26] = 8'd202; sine_rom[ 27] = 8'd204;
        sine_rom[ 28] = 8'd206; sine_rom[ 29] = 8'd209; sine_rom[ 30] = 8'd211; sine_rom[ 31] = 8'd213;
        sine_rom[ 32] = 8'd215; sine_rom[ 33] = 8'd217; sine_rom[ 34] = 8'd219; sine_rom[ 35] = 8'd221;
        sine_rom[ 36] = 8'd223; sine_rom[ 37] = 8'd225; sine_rom[ 38] = 8'd226; sine_rom[ 39] = 8'd228;
        sine_rom[ 40] = 8'd230; sine_rom[ 41] = 8'd231; sine_rom[ 42] = 8'd233; sine_rom[ 43] = 8'd234;
        sine_rom[ 44] = 8'd235; sine_rom[ 45] = 8'd237; sine_rom[ 46] = 8'd238; sine_rom[ 47] = 8'd239;
        sine_rom[ 48] = 8'd240; sine_rom[ 49] = 8'd241; sine_rom[ 50] = 8'd242; sine_rom[ 51] = 8'd242;
        sine_rom[ 52] = 8'd243; sine_rom[ 53] = 8'd244; sine_rom[ 54] = 8'd244; sine_rom[ 55] = 8'd245;
        sine_rom[ 56] = 8'd245; sine_rom[ 57] = 8'd245; sine_rom[ 58] = 8'd246; sine_rom[ 59] = 8'd246;
        sine_rom[ 60] = 8'd246; sine_rom[ 61] = 8'd246; sine_rom[ 62] = 8'd246; sine_rom[ 63] = 8'd246;
        sine_rom[ 64] = 8'd246; sine_rom[ 65] = 8'd246; sine_rom[ 66] = 8'd246; sine_rom[ 67] = 8'd246;
        sine_rom[ 68] = 8'd246; sine_rom[ 69] = 8'd245; sine_rom[ 70] = 8'd245; sine_rom[ 71] = 8'd245;
        sine_rom[ 72] = 8'd244; sine_rom[ 73] = 8'd244; sine_rom[ 74] = 8'd243; sine_rom[ 75] = 8'd242;
        sine_rom[ 76] = 8'd242; sine_rom[ 77] = 8'd241; sine_rom[ 78] = 8'd240; sine_rom[ 79] = 8'd239;
        sine_rom[ 80] = 8'd238; sine_rom[ 81] = 8'd237; sine_rom[ 82] = 8'd235; sine_rom[ 83] = 8'd234;
        sine_rom[ 84] = 8'd233; sine_rom[ 85] = 8'd231; sine_rom[ 86] = 8'd230; sine_rom[ 87] = 8'd228;
        sine_rom[ 88] = 8'd226; sine_rom[ 89] = 8'd225; sine_rom[ 90] = 8'd223; sine_rom[ 91] = 8'd221;
        sine_rom[ 92] = 8'd219; sine_rom[ 93] = 8'd217; sine_rom[ 94] = 8'd215; sine_rom[ 95] = 8'd213;
        sine_rom[ 96] = 8'd211; sine_rom[ 97] = 8'd209; sine_rom[ 98] = 8'd206; sine_rom[ 99] = 8'd204;
        sine_rom[100] = 8'd202; sine_rom[101] = 8'd199; sine_rom[102] = 8'd197; sine_rom[103] = 8'd194;
        sine_rom[104] = 8'd192; sine_rom[105] = 8'd189; sine_rom[106] = 8'd187; sine_rom[107] = 8'd184;
        sine_rom[108] = 8'd181; sine_rom[109] = 8'd178; sine_rom[110] = 8'd176; sine_rom[111] = 8'd173;
        sine_rom[112] = 8'd170; sine_rom[113] = 8'd167; sine_rom[114] = 8'd164; sine_rom[115] = 8'd161;
        sine_rom[116] = 8'd158; sine_rom[117] = 8'd155; sine_rom[118] = 8'd152; sine_rom[119] = 8'd149;
        sine_rom[120] = 8'd146; sine_rom[121] = 8'd143; sine_rom[122] = 8'd140; sine_rom[123] = 8'd137;
        sine_rom[124] = 8'd134; sine_rom[125] = 8'd131; sine_rom[126] = 8'd128; sine_rom[127] = 8'd125;
        sine_rom[128] = 8'd122; sine_rom[129] = 8'd119; sine_rom[130] = 8'd116; sine_rom[131] = 8'd113;
        sine_rom[132] = 8'd110; sine_rom[133] = 8'd107; sine_rom[134] = 8'd104; sine_rom[135] = 8'd101;
        sine_rom[136] = 8'd98;  sine_rom[137] = 8'd95;  sine_rom[138] = 8'd92;  sine_rom[139] = 8'd89;
        sine_rom[140] = 8'd86;  sine_rom[141] = 8'd83;  sine_rom[142] = 8'd80;  sine_rom[143] = 8'd77;
        sine_rom[144] = 8'd74;  sine_rom[145] = 8'd72;  sine_rom[146] = 8'd69;  sine_rom[147] = 8'd66;
        sine_rom[148] = 8'd63;  sine_rom[149] = 8'd61;  sine_rom[150] = 8'd58;  sine_rom[151] = 8'd56;
        sine_rom[152] = 8'd53;  sine_rom[153] = 8'd51;  sine_rom[154] = 8'd48;  sine_rom[155] = 8'd46;
        sine_rom[156] = 8'd44;  sine_rom[157] = 8'd41;  sine_rom[158] = 8'd39;  sine_rom[159] = 8'd37;
        sine_rom[160] = 8'd35;  sine_rom[161] = 8'd33;  sine_rom[162] = 8'd31;  sine_rom[163] = 8'd29;
        sine_rom[164] = 8'd27;  sine_rom[165] = 8'd25;  sine_rom[166] = 8'd24;  sine_rom[167] = 8'd22;
        sine_rom[168] = 8'd20;  sine_rom[169] = 8'd19;  sine_rom[170] = 8'd17;  sine_rom[171] = 8'd16;
        sine_rom[172] = 8'd15;  sine_rom[173] = 8'd13;  sine_rom[174] = 8'd12;  sine_rom[175] = 8'd11;
        sine_rom[176] = 8'd10;  sine_rom[177] = 8'd9;   sine_rom[178] = 8'd8;   sine_rom[179] = 8'd8;
        sine_rom[180] = 8'd7;   sine_rom[181] = 8'd6;   sine_rom[182] = 8'd6;   sine_rom[183] = 8'd5;
        sine_rom[184] = 8'd5;   sine_rom[185] = 8'd5;   sine_rom[186] = 8'd4;   sine_rom[187] = 8'd4;
        sine_rom[188] = 8'd4;   sine_rom[189] = 8'd4;   sine_rom[190] = 8'd4;   sine_rom[191] = 8'd4;
        sine_rom[192] = 8'd4;   sine_rom[193] = 8'd4;   sine_rom[194] = 8'd4;   sine_rom[195] = 8'd4;
        sine_rom[196] = 8'd4;   sine_rom[197] = 8'd5;   sine_rom[198] = 8'd5;   sine_rom[199] = 8'd5;
        sine_rom[200] = 8'd6;   sine_rom[201] = 8'd6;   sine_rom[202] = 8'd7;   sine_rom[203] = 8'd8;
        sine_rom[204] = 8'd8;   sine_rom[205] = 8'd9;   sine_rom[206] = 8'd10;  sine_rom[207] = 8'd11;
        sine_rom[208] = 8'd12;  sine_rom[209] = 8'd13;  sine_rom[210] = 8'd15;  sine_rom[211] = 8'd16;
        sine_rom[212] = 8'd17;  sine_rom[213] = 8'd19;  sine_rom[214] = 8'd20;  sine_rom[215] = 8'd22;
        sine_rom[216] = 8'd24;  sine_rom[217] = 8'd25;  sine_rom[218] = 8'd27;  sine_rom[219] = 8'd29;
        sine_rom[220] = 8'd31;  sine_rom[221] = 8'd33;  sine_rom[222] = 8'd35;  sine_rom[223] = 8'd37;
        sine_rom[224] = 8'd39;  sine_rom[225] = 8'd41;  sine_rom[226] = 8'd44;  sine_rom[227] = 8'd46;
        sine_rom[228] = 8'd48;  sine_rom[229] = 8'd51;  sine_rom[230] = 8'd53;  sine_rom[231] = 8'd56;
        sine_rom[232] = 8'd58;  sine_rom[233] = 8'd61;  sine_rom[234] = 8'd63;  sine_rom[235] = 8'd66;
        sine_rom[236] = 8'd69;  sine_rom[237] = 8'd72;  sine_rom[238] = 8'd74;  sine_rom[239] = 8'd77;
        sine_rom[240] = 8'd80;  sine_rom[241] = 8'd83;  sine_rom[242] = 8'd86;  sine_rom[243] = 8'd89;
        sine_rom[244] = 8'd92;  sine_rom[245] = 8'd95;  sine_rom[246] = 8'd98;  sine_rom[247] = 8'd101;
        sine_rom[248] = 8'd104; sine_rom[249] = 8'd107; sine_rom[250] = 8'd110; sine_rom[251] = 8'd113;
        sine_rom[252] = 8'd116; sine_rom[253] = 8'd119; sine_rom[254] = 8'd122; sine_rom[255] = 8'd125;
    end

    always @(*) begin
        sample_data = sine_rom[phase];
    end

    assign sample_valid = enable;

endmodule
