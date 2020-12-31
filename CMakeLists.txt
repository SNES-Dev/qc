cmake_minimum_required(VERSION 3.15)

project(qc C ASM)

message(STATUS "Building qc floating point libraries")
message(STATUS "QC: Using C Compiler ${CMAKE_C_COMPILER}")
message(STATUS "QC: Using ASM Compiler ${CMAKE_ASM_COMPILER}")

configure_file(include/qc_config.h.in include/qc_config.h)

include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/include)

add_library(qc STATIC qc_float.c qc_int.S
        include/qc_base.h
        ${CMAKE_CURRENT_BINARY_DIR}/include/qc_config.h
        include/qc_float.h
        include/qc_int.h
        )

