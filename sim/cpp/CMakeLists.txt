#
# This file is part of VERILOG_TEMPLATE.
#

#####################################
# Verilator simulation source files #
#####################################
list(APPEND VERILATOR_SOURCES
    top_tb.cpp
)

############################
# Verilator module headers #
############################
list(APPEND VERILATOR_INCLUDE_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/sim/verilog
    ${CMAKE_BINARY_DIR}/rtl
)

####################################
# Verilator simulation executables #
####################################
foreach(SIM ${VERILATOR_SOURCES})
    string(REPLACE ".cpp" "_sim" SIM_NAME ${SIM})
    add_executable(${SIM_NAME} ${SIM})
    target_link_libraries(${SIM_NAME}
        PRIVATE ${VERILOG_TARGETS} ${VERILOG_SIM_TARGETS}
    )
    target_include_directories(${SIM_NAME} PUBLIC ${VERILATOR_INCLUDE_DIRS})
endforeach()
