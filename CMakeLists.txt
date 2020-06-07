cmake_minimum_required(VERSION 3.15)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
include(HackCMake)
if(DEFINED SNESDEV_BOOTSTRAP)
    # We are buidling snes-dev, or a toolchain like snes-dev, compile qc using that target
    message(STATUS "Building host qc library for ${SNESDEV_TARGET_NAME}")
    if(TARGET ${SNESDEV_TARGET_NAME}-cc)
        set(qc_compiler ${SNESDEV_TARGET_NAME}-cc)
    elseif(TARGET clang)
        set(qc_compiler clang)
    else()
        message(ERROR "Cannot find cross-compiler target in toolchain building")
    endif()
endif()

project(qc C ASM)

set(CMAKE_C_STANDARD 99)

if(DEFINED SNESDEV_SYSROOT)
    set(QC_INSTALL_ROOTDIR ${SNESDEV_SYSROOT})
else()
    set(QC_INSTALL_ROOTDIR ${CMAKE_INSTALL_PREFIX})
endif()

configure_file(include/qc_config.h.in include/qc_config.h)

add_qc_library(qc include/qc_base.h include/qc_float.h include/qc_int.h qc_float.c qc_int.S)

set_property(TARGET qc PROPERTY INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIRECTORY}/include ${CMAKE_CURRENT_BINARY_DIR}/include)

set_property(TARGET qc PROPERTY COMPILE_OPTIONS -nostdinc -ffreestanding)




