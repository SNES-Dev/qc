#include <qc_config.h>

#define __qc_op_name(type,op)\
    __qc_op_##op##_##type

#define __qc_def_op(class,type,name,symbol)\
    {"class": __qc_quoted(class),"operation":__qc_quoted(symbol), "call":__qc_quoted(__qc_op_name(type,name))}

#define __qc_def_nop(type,op,symbol)
    __qc_def_op(0,type,op,symbol)

#define __qc_def_uop(type,op,symbol)\
    __qc_def_op(1,type,op,symbol)

#define __qc_def_bop(type,op,symbol)\
    __qc_def_op(2,type,op,symbol)

#define __qc_def_top(type,op,symbol)\
    __qc_def_op(3,type,op,symbol)


#define __qc_float_nop(type,repr_t,name,symbol)\
    __qc_def_nop(repr_t,name,symbol)
#define __qc_float_bop(type,repr_t,name,symbol)\
    __qc_def_bop(repr_t,name,symbol)
#define __qc_float_uop(type,repr_t,name,symbol)\
    __qc_def_uop(repr_t,name,symbol)
#define __qc_float_top(type,repr_t,name,symbol)\
    __qc_def_top(repr_t,name,symbol)

#define __qc_float_ops(type,repr_t)\
    __qc_float_bop(type,repr_t,add,+),\
    __qc_float_bop(type,repr_t,sub,-),\
    __qc_float_bop(type,repr_t,mul,*),\
    __qc_float_bop(type,repr_t,div,/),\
    __qc_float_uop(type,repr_t,neg,-),\
    __qc_float_nop(type,repr_t,inf,inf),\
    __qc_float_nop(type,repr_t,nan,nan),\
    __qc_float_top(type,repr_t,fma,fma),\
    __qc_float_uop(type,repr_t,abs,abs),\
    __qc_float_bop(type,repr_t,max,max),\
    __qc_float_bop(type,repr_t,min,min),\
    __qc_float_uop(type,repr_t,exp,exp),\
    __qc_float_uop(type,repr_t,exp2,exp2),\
    __qc_float_uop(type,repr_t,expm1,expm1),\
    __qc_float_uop(type,repr_t,log,log),\
    __qc_float_uop(type,repr_t,log10,log10),\
    __qc_float_uop(type,repr_t,log2,log2),\
    __qc_float_uop(type,repr_t,log1p,log1p),\
    __qc_float_bop(type,repr_t,pow,pow),\
    __qc_float_uop(type,repr_t,sqrt,sqrt),\
    __qc_float_uop(type,repr_t,cbrt,cbrt),\
    __qc_float_bop(type,repr_t,hypot,hypot),\
    __qc_float_uop(type,repr_t,sin,sin),\
    __qc_float_uop(type,repr_t,cos,cos),\
    __qc_float_uop(type,repr_t,tan,tan),\
    __qc_float_uop(type,repr_t,asin,asin),\
    __qc_float_uop(type,repr_t,acos,acos),\
    __qc_float_uop(type,repr_t,atan,atan),\
    __qc_float_bop(type,repr_t,atan2,atan2),\
    __qc_float_uop(type,repr_t,sinh,sinh),\
    __qc_float_uop(type,repr_t,cosh,cosh),\
    __qc_float_uop(type,repr_t,tanh,tanh),\
    __qc_float_uop(type,repr_t,asinh,asinh),\
    __qc_float_uop(type,repr_t,acosh,acosh),\
    __qc_float_uop(type,repr_t,atanh,atanh),\
    __qc_float_uop(type,repr_t,erf,erf),\
    __qc_float_uop(type,repr_t,erfc,erfc),\
    __qc_float_uop(type,repr_t,tgamma,tgamma),\
    __qc_float_uop(type,repr_t,lgamma,lgamma)


#define __qc_fixed_ops(type,repr_t)\
    __qc_def_bop(type,add,+),\
    __qc_def_bop(type,sub,-),\
    __qc_def_bop(type,mul,*),\
    __qc_def_bop(type,div,/),\
    __qc_def_uop(type,neg,-),\
    __qc_def_top(type,fma,fma),\
    __qc_def_uop(type,abs,abs),\
    __qc_def_bop(type,max,max),\
    __qc_def_bop(type,min,min),\
    __qc_def_uop(type,exp,exp),\
    __qc_def_uop(type,exp2,exp2),\
    __qc_def_uop(type,expm1,expm1),\
    __qc_def_uop(type,log,log),\
    __qc_def_uop(type,log10,log10),\
    __qc_def_uop(type,log2,log2),\
    __qc_def_uop(type,log1p,log1p),\
    __qc_def_bop(type,pow,pow),\
    __qc_def_uop(type,sqrt,pow),\
    __qc_def_uop(type,cbrt,cbrt),\
    __qc_def_bop(type,hypot,hypot),\
    __qc_def_uop(type,sin,sin),\
    __qc_def_uop(type,cos,cos),\
    __qc_def_uop(type,tan,tan),\
    __qc_def_uop(type,asin,asin),\
    __qc_def_uop(type,acos,acos),\
    __qc_def_uop(type,atan,atan),\
    __qc_def_bop(type,atan2,atan2),\
    __qc_def_uop(type,sinh,sinh),\
    __qc_def_uop(type,cosh,cosh),\
    __qc_def_uop(type,tanh,tanh),\
    __qc_def_uop(type,asinh,asinh),\
    __qc_def_uop(type,acosh,acosh),\
    __qc_def_uop(type,atanh,atanh),\
    __qc_def_uop(type,erf,erf),\
    __qc_def_uop(type,erfc,erfc),\
    __qc_def_uop(type,tgamma,tgamma),\
    __qc_def_uop(type,lgamma,lgamma)

#define __qc_int_ops(type)\
    __qc_def_bop(type,add,+),\
    __qc_def_bop(type,sub,-),\
    __qc_def_bop(type,mul,*),\
    __qc_def_bop(type,div,/),\
    __qc_def_bop(type,band,&),\
    __qc_def_bop(type,bor,|),\
    __qc_def_bop(type,bxor,^),\
    __qc_def_uop(type,neg,-),\
    __qc_def_uop(type,bnot,~),\
    __qc_def_div_ops(type)

#define __qc_def_div_ops(type)\
    {"class": "div","operation":"div", "call":__qc_quoted(__qc_div_##type)}