
__qc_def_float(float,32,7,23);
__qc_def_float(double,64,11,54);
#ifndef __QC_NO_I128
__qc_def_float(long double,128,15,114);
#endif
__qc_def_float(float,16,5,12);

__qc_def_fixed(short _Fract,16,8);
__qc_def_fixed(int _Fract,32,16);
__qc_def_fixed(long long _Fract,64,32);
#ifndef __QC_NO_I128
__qc_def_fixed(_UInt128 _Fract,128.64);
#endif
