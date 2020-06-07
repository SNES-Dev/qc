__qc_def_int_type(char,8);
__qc_def_int_type(short,16);
__qc_def_int_type(int,32);
__qc_def_int_type(long long,64);
#ifndef __QC_NO_I128
__qc_def_int_type(long long,128);
#endif



__qc_def_ext_int_t(char,_IntSigAtomic,_UIntSigAtomic,16);
__qc_def_ext_int_t(int,_IntPtr,_UIntPtr,24);
__qc_def_ext_int_t(short,_IntShortPtr,_UIntShortPtr,16);