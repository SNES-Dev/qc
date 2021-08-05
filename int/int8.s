
__fixed_add8:
__uint_add8:
__int_add8:
    txa
    clc
    sty __r1,%D
    adc __r1,%D
    rtl

__fixed_sub8:
__uint_sub8:
__int_sub8:
    txa
    clc
    sty __r1,%D
    sbc __r1,%D
    rtl

