//
// This file is part of VERILOG_TEMPLATE.
//

//
// All signals must be explicitly declared
//
`default_nettype none

module top_tb (i_clk, i_rst, o_count);
    parameter CW = 16;

    input   wire               i_clk;
    input   wire               i_rst;

    output  wire   [(CW-1):0]  o_count;

    counter #(CW)
    test_counter (i_clk, i_rst, o_count);
endmodule
