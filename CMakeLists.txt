cmake_minimum_required(VERSION 3.15)
project(qc C ASM)

set(CMAKE_C_STANDARD 99)

set(TMP_CMAKE_C_COMPILER ${CMAKE_C_COMPILER})
set(TMP_CMAKE_ASM_COMPILER ${CMAKE_ASM_COMPILER})
set(TMP_CMAKE_C_COMPILER_TARGET ${CMAKE_C_COMPILER_TARGET})
set(TMP_CMAKE_ASM_COMPILER_TARGET ${CMAKE_ASM_COMPILER_TARGET})

if(DEFINED SNESDEV_TARGET_NAME)
    # We are buidling snes-dev, or a toolchain like snes-dev, compile qc using that target
    message(INFO "Buidling host qc library for ${SNESDEV_TARGET_NAME}")
    if(TARGET ${SNESDEV_TARGET_NAME}-cc)
        set(CMAKE_C_COMPILER $<TARGET_FILE:${SNESDEV_TARGET_NAME}-cc>)
	set(qc_compiler ${SNESDEV_TARGET_NAME}-cc)
    elseif(TARGET clang)
	set(CMAKE_C_COMPILER $<TARGET_FILE:clang>)
	set(qc_compiler clang)
    else()
	message(ERROR "Cannot find cross-compiler target in toolchain building")
    endif()
    set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
    set(CMAKE_C_COMPILER_TARGET ${SNESDEV_TARGET_NAME})
    set(CMAKE_ASM_COMPILER_TARGET ${SNESDEV_TARGET_NAME})
endif()

if(DEFINED SNESDEV_SYSROOT)
    set(QC_INSTALL_ROOTDIR ${SNESDEV_SYSROOT})
else()
    set(QC_INSTALL_ROOTDIR ${CMAKE_INSTALL_PREFIX})
endif()

include_directories(include)

add_library(qc STATIC include/qc_base.h include/qc_int.h src/qc_int.S src/qc_float.c include/qc_float.h)

target_compile_options(qc PRIVATE -nostdinc -ffreestanding)

install(TARGETS qc DESTINATION ${QC_INSTALL_ROOTDIR}/lib)

set(CMAKE_C_COMPILER ${TMP_CMAKE_C_COMPILER})
set(CMAKE_ASM_COMPILER ${TMP_CMAKE_ASM_COMPILER})
set(CMAKE_C_COMPILER_TARGET ${TMP_CMAKE_C_COMPILER_TARGET})
set(CMAKE_ASM_COMPILER_TARGET ${TMP_CMAKE_ASM_COMPILER_TARGET})

