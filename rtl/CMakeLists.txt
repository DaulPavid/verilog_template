#
# This file is part of VERILOG_TEMPLATE.
#

###############################
# Verilog module source files #
###############################
list(APPEND VERILOG_MODULES
    counter.v
)

############################
# Verilog module libraries #
############################
foreach(MODULE ${VERILOG_MODULES})
    string(REPLACE ".v" "" MODULE_NAME ${MODULE})
    add_library(${MODULE_NAME})
    verilate(${MODULE_NAME}
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERILATOR_ARGS ${VERILATOR_ARGS}
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}
    )

    list(APPEND VERILOG_TARGETS ${MODULE_NAME})
endforeach()

################################
# Set the verilog target scope #
################################
set(VERILOG_AUTODOC "${VERILOG_MODULES}" PARENT_SCOPE)
set(VERILOG_TARGETS "${VERILOG_TARGETS}" PARENT_SCOPE)
