#
# This file is part of VERILOG_TEMPLATE.
#

############################
# General project settings #
############################
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(VERILOG_TEMPLATE CXX)

enable_testing()

# Set the cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/packages")

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
add_subdirectory(docs)
add_subdirectory(rtl)
add_subdirectory(sim/verilog)
add_subdirectory(sim/cpp)
