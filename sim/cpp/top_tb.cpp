/*!
 *  This file is part of VERILOG_TEMPLATE.
 */

#include <verilated.h>

#include <stdio.h>
#include <stdlib.h>

#include "Vtop_tb.h"

int
main (int argc, char* argv[])
{
    Verilated::commandArgs(argc, argv);

    vluint64_t num_ticks = 1000;

    Vtop_tb top_tb;

    top_tb.i_clk = 1;
    top_tb.i_rst = 0;

    vluint64_t sim_tick = 0;

    printf("[%ld] - Started verilator simulation\n", sim_tick);

    while (!Verilated::gotFinish())
    {
        sim_tick++;

        top_tb.i_rst = 0;
        top_tb.i_clk = !top_tb.i_clk;
        top_tb.eval();

        printf("[%04ld] - i_clk = 0x%x, i_rst = 0x%x, o_count = 0x%x\n",
               sim_tick, top_tb.i_clk, top_tb.i_rst, top_tb.o_count);

        if (sim_tick >= num_ticks) break;
    }

    printf("[%04ld] - Exited simulation\n", sim_tick);

    top_tb.final();

    return EXIT_SUCCESS;
}
