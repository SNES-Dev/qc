
__fixed_add16:
__uint_add16:
__int_add16:
    rep #$10
    txa
    clc
    sty __r1,%D
    adc __r1,%D
    sep #$20
    rtl

__fixed_sub16:
__uint_sub16:
__int_sub16:
    rep #$10
    txa
    clc
    sty __r1,%D
    sbc __r1,%D
    sep #$20
    rtl
