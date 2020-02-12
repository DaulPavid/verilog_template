//
// This file is part of VERILOG_TEMPLATE.
//

// All signals must be explicitly declared
`default_nettype none

module counter (i_clk, i_rst, o_count);
    parameter CW = 16;

    input    wire              i_clk;
    input    wire              i_rst;

    output   reg   [(CW-1):0]  o_count;

    initial o_count = 0;
    always @(posedge i_clk)
    begin
        if (i_rst)
            o_count <= 0;
        else
            o_count <= o_count + 1'b1;
    end
endmodule
