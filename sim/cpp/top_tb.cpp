/*!
 *  This file is part of VERILOG_TEMPLATE.
 */

#include <verilated.h>
#include <verilated_vcd_c.h>

#include <stdio.h>
#include <stdlib.h>

#include "Vtop_tb.h"

int
main (int argc, char* argv[])
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    vluint64_t num_ticks = 1000;
    vluint64_t sim_tick = 0;

    Vtop_tb top_tb;

    VerilatedVcdC vcd;

    top_tb.trace(&vcd, 99);
    top_tb.i_clk = 1;
    top_tb.i_rst = 0;

    vcd.open("counter.vcd");

    printf("[%ld] - Started verilator simulation\n", sim_tick);

    while (!Verilated::gotFinish())
    {
        sim_tick++;

        top_tb.i_rst = 0;
        top_tb.i_clk = !top_tb.i_clk;
        top_tb.eval();

        printf("[%04ld] - i_clk = 0x%x, i_rst = 0x%x, o_count = 0x%x\n",
               sim_tick, top_tb.i_clk, top_tb.i_rst, top_tb.o_count);

        vcd.dump(sim_tick);

        if (sim_tick >= num_ticks) break;
    }

    printf("[%04ld] - Exited simulation\n", sim_tick);

    top_tb.final();

    vcd.close();

    return EXIT_SUCCESS;
}
