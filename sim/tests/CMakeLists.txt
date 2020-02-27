#
# This file is part of VERILOG_TEMPLATE.
#

##################################
# SymbiYosys configuration files #
##################################
list(APPEND SBY_CONFIGS
    counter.sby
)

#########################################
# Find SymbiYosys and required programs #
#########################################

# Find Yosys-SMTBMC
find_program(SMTBMC
    NAMES yosys-smtbmc
    HINTS /usr/bin /usr/local/bin
)
if(${SMTBMC-NOTFOUND})
    message(WARNING "Unable to find Yosys-SMTBMC; tests might fail")
endif()

# Find Z3 Theorem Prover
find_program(Z3
    NAMES z3
    HINTS /usr/bin /usr/local/bin
)
if(${Z3-NOTFOUND})
    message(WARNING "Unable to find Z3; tests might fail")
endif()

# Find Yices 2 Solver (Necessary for Bounded Model Check [BMC] tests)
find_program(YICES
    NAMES yices
    HINTS /usr/bin /usr/local/bin
)
if(${YICES-NOTFOUND})
    message(WARNING "Unable to find Yices 2; tests might fail")
endif()

# Find SymbiYosys frontend
find_program(SBY
    NAMES sby
    HINTS /usr/bin /usr/local/bin
)
if(${SBY-NOTFOUND})
    message(WARNING "Unable to find SymbiYosys; tests will not run")
else()
    foreach(CONFIG ${SBY_CONFIGS})
        string(REPLACE ".sby" "" CONFIG_NAME ${CONFIG})
        add_test(NAME SBY_${CONFIG_NAME}
            COMMAND ${SBY} -f ${CONFIG}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach()
endif()
