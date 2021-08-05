
.global __fixed_add32
.global __int_add32
.global __uint_add32 

.global __fixed_sub32
.global __uint_sub32
.global __int_sub32

__fixed_add32:
__uint_add32:
__int_add32:
    rep #$10
    sep #$20
    lda __r1,%d
    adc __r2,%d
    sta __r0,%d
    lda __r1+2,%d
    adc __r2+2,%d
    sta __r0,%d
    rtl

__fixed_sub32:
__uint_sub32:
__int_sub32:
    rep #$10
    sep #$20
    lda __r1,%d
    sbc __r2,%d
    sta __r0,%d
    lda __r1+2,%d
    sbc __r2+2,%d
    sta __r0,%ds
    rtl

