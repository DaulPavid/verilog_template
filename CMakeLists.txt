#
# This file is part of VERILOG_TEMPLATE.
#

############################
# General project settings #
############################
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(VERILOG_TEMPLATE C CXX)

enable_testing()

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set the CXX standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Verilator arguments
set(VERILATOR_ARGS "-Wall")

# Available build options
option(BUILD_SIM     "Build testbench simulations"  ON)
option(BUILD_DOC     "Build the core documentation" ON)
option(ENABLE_FORMAL "Enable formal verification"   ON)

##################################
# Project packages and libraries #
##################################
find_package(verilator)

###########################
# Project sub-directories #
###########################
add_subdirectory(rtl)

if(BUILD_DOC)
    message(STATUS "Generating the documentation")
    add_subdirectory(docs)
endif()

if(BUILD_SIM)
    message(STATUS "Building testbenches and simulations")
    add_subdirectory(sim/verilog)
    add_subdirectory(sim/cpp)
endif()

if(ENABLE_FORMAL)
    message(STATUS "Enabling formal tests")
    add_subdirectory(sim/tests)
endif()
