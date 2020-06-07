//
// Created by chorm on 2020-01-02.
//

#ifndef SNES_DEV_QC_FLOAT_H
#define SNES_DEV_QC_FLOAT_H

#include <qc_base.h>
#include <qc_int.h>

#define __qc_float_impl_bop(type,repr_t,name,symbol)\
    __qc_inline __qc_def_bop(type,name,symbol){\
        repr_t __a_repr = {.val=a};\
        repr_t __b_repr = {.val=b};\
        return __qc_call_op(repr_t,name,__a_repr,__b_repr).val;\
    }
#define __qc_float_impl_top(type,repr_t,name,symbol)\
    __qc_inline __qc_def_top(type,name,symbol){\
        repr_t __a_repr = {.val=a};\
        repr_t __b_repr = {.val=b};\
        repr_t __c_repr = {.val=c};\
        return __qc_call_op(repr_t,name,__a_repr,__b_repr,__c_repr).val;\
    }
#define __qc_float_impl_uop(type,repr_t,name,symbol)\
    __qc_inline __qc_def_uop(type,name,symbol){\
    repr_t __val_repr = {.val=val};\
    return __qc_call_op(repr_t,name,__val_repr).val;\
    }
#define __qc_float_impl_nop(type,repr_t,name,symbol)\
    __qc_inline __qc_def_nop(type,names,ymbol){\
        return __qc_call_op(repr_t,name).val;\
    }

#define __qc_float_bop(type,repr_t,name,symbol)\
    __qc_def_bop(repr_t,name,symbol);\
    __qc_float_impl_bop(type,repr_t,name,symbol)

#define __qc_float_uop(type,repr_t,name,symbol)\
    __qc_def_uop(repr_t,name,symbol);\
    __qc_float_impl_uop(type,repr_t,name,symbol)
#define __qc_float_nop(type,repr_t,name,symbol)\
    __qc_def_nop(repr_t,name,symbol);\
    __qc_float_impl_nop(type,repr_t,name,symbol)
#define __qc_float_top(type,repr_t,name,symbol)\
    __qc_def_top(repr_t,name,symbol);\
    __qc_float_impl_top(type,repr_t,name,symbol)

#define __qc_float_ops(type,repr_t)\
    __qc_float_bop(type,repr_t,add,+);\
    __qc_float_bop(type,repr_t,sub,-);\
    __qc_float_bop(type,repr_t,mul,*);\
    __qc_float_bop(type,repr_t,div,/);\
    __qc_float_uop(type,repr_t,neg,-);\
    __qc_float_nop(type,repr_t,inf,inf);\
    __qc_float_nop(type,repr_t,nan,nan);\
    __qc_float_top(type,repr_t,fma,fma);\
    __qc_float_uop(type,repr_t,abs,abs);\
    __qc_float_bop(type,repr_t,max,max);\
    __qc_float_bop(type,repr_t,min,min);\
    __qc_float_uop(type,repr_t,exp,exp);\
    __qc_float_uop(type,repr_t,exp2,exp2);\
    __qc_float_uop(type,repr_t,expm1,expm1);\
    __qc_float_uop(type,repr_t,log,log);\
    __qc_float_uop(type,repr_t,log10,log10);\
    __qc_float_uop(type,repr_t,log2,log2);\
    __qc_float_uop(type,repr_t,log1p,log1p);\
    __qc_float_bop(type,repr_t,pow,pow);\
    __qc_float_uop(type,repr_t,sqrt,sqrt);\
    __qc_float_uop(type,repr_t,cbrt,cbrt);\
    __qc_float_bop(type,repr_t,hypot,hypot);\
    __qc_float_uop(type,repr_t,sin,sin);\
    __qc_float_uop(type,repr_t,cos,cos);\
    __qc_float_uop(type,repr_t,tan,tan);\
    __qc_float_uop(type,repr_t,asin,asin);\
    __qc_float_uop(type,repr_t,acos,acos);\
    __qc_float_uop(type,repr_t,atan,atan);\
    __qc_float_bop(type,repr_t,atan2,atan2);\
    __qc_float_uop(type,repr_t,sinh,sinh);\
    __qc_float_uop(type,repr_t,cosh,cosh);\
    __qc_float_uop(type,repr_t,tanh,tanh);\
    __qc_float_uop(type,repr_t,asinh,asinh);\
    __qc_float_uop(type,repr_t,acosh,acosh);\
    __qc_float_uop(type,repr_t,atanh,atanh);\
    __qc_float_uop(type,repr_t,erf,erf);\
    __qc_float_uop(type,repr_t,erfc,erfc);\
    __qc_float_uop(type,repr_t,tgamma,tgamma);\
    __qc_float_uop(type,repr_t,lgamma,lgamma)


#define __qc_fixed_ops(type,repr_t)\
    __qc_def_bop(type,add,+);\
    __qc_def_bop(type,sub,-);\
    __qc_def_bop(type,mul,*);\
    __qc_def_bop(type,div,/);\
    __qc_def_uop(type,neg,-);\
    __qc_def_top(type,fma,fma);\
    __qc_def_uop(type,abs,abs);\
    __qc_def_bop(type,max,max);\
    __qc_def_bop(type,min,min);\
    __qc_def_uop(type,exp,exp);\
    __qc_def_uop(type,exp2,exp2);\
    __qc_def_uop(type,expm1,expm1);\
    __qc_def_uop(type,log,log);\
    __qc_def_uop(type,log10,log10);\
    __qc_def_uop(type,log2,log2);\
    __qc_def_uop(type,log1p,log1p);\
    __qc_def_bop(type,pow,pow);\
    __qc_def_uop(type,sqrt,pow);\
    __qc_def_uop(type,cbrt,cbrt);\
    __qc_def_bop(type,hypot,hypot);\
    __qc_def_uop(type,sin,sin);\
    __qc_def_uop(type,cos,cos);\
    __qc_def_uop(type,tan,tan);\
    __qc_def_uop(type,asin,asin);\
    __qc_def_uop(type,acos,acos);\
    __qc_def_uop(type,atan,atan);\
    __qc_def_bop(type,atan2,atan2);\
    __qc_def_uop(type,sinh,sinh);\
    __qc_def_uop(type,cosh,cosh);\
    __qc_def_uop(type,tanh,tanh);\
    __qc_def_uop(type,asinh,asinh);\
    __qc_def_uop(type,acosh,acosh);\
    __qc_def_uop(type,atanh,atanh);\
    __qc_def_uop(type,erf,erf);\
    __qc_def_uop(type,erfc,erfc);\
    __qc_def_uop(type,tgamma,tgamma);\
    __qc_def_uop(type,lgamma,lgamma)

#define __qc_def_float(type,bits,expbits,sigbits)\
    typedef type _Float##bits __qc_sized_float(bits);\
    typedef union {\
        _Float##bits val;\
        _UInt##bits raw:bits;\
        struct{\
            _UInt##bits sign:1;\
            _UInt##bits exp:expbits;\
            _UInt##bits sig:sigbits;\
        }__repr;\
    }__qc_float_##bits;\
    __qc_float_ops(_Float##bits,__qc_float_##bits)

#defime __qc_def_fixed(type,bits,fixed_at)\
    typedef type _Fixed##bits __qc_sized_fixed(bits);\
    enum { __QC_FIXED_BREAK_##bits};\
    __qc_float_ops(_Fixed##bits,__qc_fixed_##bits)

#include "qc_float.h"

#define FLT_RADIX 2



#endif //SNES_DEV_QC_FLOAT_H
