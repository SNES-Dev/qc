//
// Created by chorm on 2020-01-02.
//

#ifndef SNES_DEV_QC_BASE_H
#define SNES_DEV_QC_BASE_H

#include <qc_config.h>

#ifdef __cplusplus
#define __qc_extern extern"C"
#define __qc_inline inline
#else
#define __qc_extern
#define __qc_inline inline static
#endif

#define __qc_op_name(type,op)\
    __qc_op_##op##_##type

#define __qc_def_nop(type,op,symbol)\
    __qc_extern type (__qc_op_name(type,op))()
#define __qc_def_bop(type,op,symbol)\
    __qc_extern type (__qc_op_name(type,op))(type a,type b)
#define __qc_def_uop(type,op,symbol)\
    __qc_extern type (__qc_op_name(type,op))(type val)
#define __qc_def_top(type,op,symbol)\
    __qc_extern type (__qc_op_name(type,op))(type a,type b,type c)

#define __qc_call_op(type,op,...)\
    (__qc_op_name(type,op))(__VA_ARGS__)

#define __qc_sized_int(sz) __attribute__((mode(__qc_size_int_md(sz))))
#define __qc_sized_float(sz) __attribute__((mode(__qc_size_float_md(sz))))
#define __qc_sized_fixed(sz) __attribute__((mode(__qc_size_fixed_md(sz))))

#endif //SNES_DEV_QC_BASE_H
