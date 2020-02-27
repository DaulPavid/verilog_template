//
// This file is part of VERILOG_TEMPLATE.
//

/// # Counter Example Specification
///
/// ## Overview
///
/// This is an example counter which serves as a filler module for the
/// template.
///
/// ## IO Ports
///
/// There are only a few ports on this module because it's just a simple
/// counter.
///
/// Port     | Direction | Bus Width | Description
/// ---------|:----------|:----------|:-------------
/// i_clk    | Input     | 1         | Counter clock
/// i_rst    | Input     | 1         | Counter reset
/// o_count  | Output    | 16 (VAR)  | Counter output register
///
/// ## Registers
///
/// The counter has no runtime configuration registers.
///

//
// All signals must be explicitly declared
//
`default_nettype none

module counter (i_clk, i_rst, o_count);
    parameter CW = 16;

    localparam MAX_COUNT = 10;

    input    wire              i_clk;
    input    wire              i_rst;

    output   reg   [(CW-1):0]  o_count;

    wire stb;

    assign stb = (o_count == MAX_COUNT);

    initial o_count = 0;
    always @(posedge i_clk)
    begin
        if (i_rst || stb)
            o_count <= 0;
        else
            o_count <= o_count + 1'b1;
    end

    `ifdef FORMAL
        always @(posedge i_clk)
        begin
            assert(o_count <= MAX_COUNT);
        end
    `endif
endmodule
