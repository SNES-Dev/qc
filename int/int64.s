
.global __fixed_add64
.global __int_add64
.global __uint_add64

.global __fixed_sub64
.global __uint_sub64
.global __int_sub64

__fixed_add64:
__uint_add64:
__int_add64:
    .idx8
    rep #$10
    sep #$20
    lda __r1,%d
    adc __r3,%d
    sta (__r0,%d)
    lda __r1+2,%d
    adc __r3+2,%d
    ldy #2
    sta (__r0,%d),%y
    lda __r2,%d
    adc __r4,%d
    ldy #4
    sta (__r0,%d),%y
    lda __r2+2,%d
    adc __r4+2,%d
    ldy #6
    sta (__r0,%d),%y
    rtl

__fixed_sub64:
__uint_sub64:
__int_sub64:
    .idx8
    rep #$10
    sep #$20
    lda __r1,%d
    sbc __r3,%d
    sta (__r0,%d)
    lda __r1+2,%d
    sbc __r3+2,%d
    ldy #2
    sta (__r0,%d),%y
    lda __r2,%d
    sbc __r4,%d
    ldy #4
    sta (__r0,%d),%y
    lda __r2+2,%d
    sbc __r4+2,%d
    ldy #6
    sta (__r0,%d),%y
    rtl
