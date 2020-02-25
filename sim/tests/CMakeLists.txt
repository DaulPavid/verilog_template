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
find_program(SMTBMC
    NAMES yosys-smtbmc
    HINTS /usr/bin /usr/local/bin
)

if(${SMTBMC-NOTFOUND})
    message(WARNING "Unable to find Yosys-SMTBMC for testing")
endif()

# Necessary solver for Bounded Model Check (BMC) tests
find_program(YICES
    NAMES yices
    HINTS /usr/bin /usr/local/bin
)

if(${YICES-NOTFOUND})
    message(WARNING "Unable to find Yices 2 for testing")
endif()

find_program(SBY
    NAMES sby
    HINTS /usr/bin /usr/local/bin
)

if(${SBY-NOTFOUND})
    message(WARNING "Unable to find SymbiYosys for testing")
else()
    foreach(CONFIG ${SBY_CONFIGS})
        add_test(NAME SBY_${CONFIG}
            COMMAND ${SBY} -f ${CONFIG}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach()
endif()
