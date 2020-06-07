#include <qc_base.h>


.global __qc_op_name(_UInt8,add)
.global __qc_op_name(_Int8,add)
.global __qc_op_name(_UInt8,sub)
.global __qc_op_name(_Int8,sub)
.global __qc_op_name(_UInt16,add)
.global __qc_op_name(_Int16,add)
.global __qc_op_name(_Fixed16,add)
.global __qc_op_name(_Fixed16,sub)
.global __qc_op_name(_UInt16,sub)
.global __qc_op_name(_Int16,sub)
.global __qc_op_name(_UInt32,add)
.global __qc_op_name(_Int32,add)
.global __qc_op_name(_Fixed32,add)
.global __qc_op_name(_Fixed32,sub)
.global __qc_op_name(_UInt32,sub)
.global __qc_op_name(_Int32,sub)
.global __qc_op_name(_UInt64,add)
.global __qc_op_name(_Int64,add)
.global __qc_op_name(_Fixed64,add)
.global __qc_op_name(_Fixed64,sub)
.global __qc_op_name(_UInt64,sub)
.global __qc_op_name(_Int64,sub)

.sub __qc_op_name(_UInt8,add) __qc_op_name(_Int8,add)
    txa
    sty __al
    add __al
    rtl
.endsub

.sub __qc_op_name(_UInt8,sub) __qc_op_name(_Int8,sub)
    txa
    sty __al
    sub __al
    rtl

.sub __qc_op_name(_Fixed16,add) __qc_op_name(_UInt16,add) __qc_op_name(_Int16,add)
    rep #$20
    .m16
    txa
    sty __al
    add __al
    rtl
.endsub

.sub __qc_op_name(_Fixed32,add) __qc_op_name(_UInt32,add)  __qc_op_name(_Int32,add)
    rep #$20
    .m16
    lda __di
    add __si
    sta __ax
    lda __edi
    adc __esi
    sta __eax
    sep #$20
    rtl
.endsub

.sub __qc_op_name(_Fixed32,sub) __qc_op_name(_UInt32,sub) __qc_op_name(_Int32,sub)
    rep #$20
    .m16
    lda __edi
    sub __esi
    sta __eax
    lda __di
    sbc __si
    sta __ax
    sep #$20
    rtl
.endsub

.sub __qc_op_name(_Fixed64,add) __qc_op_name(_UInt64,add) __qc_op_name(_Int64,add)
    rep #$20
    .m16
    lda __esi
    add __ecx
    sta __eax
    lda __si
    adc __cx
    sta __ax
    lda __edi
    adc __edx
    sta __ebx
    lda __di
    adc __dx
    sta __bx
    sep #$20
    rtl
.endsub

.sub __qc_op_name(_Fixed64,sub) __qc_op_name(_UInt64,sub) __qc_op_name(_Int64,sub)
    rep #$20
    .m16
    lda __esi
    sub __ecx
    sta __eax
    lda __si
    sbc __cx
    sta __ax
    lda __edi
    sbc __edx
    sta __ebx
    lda __di
    sbc __dx
    sta __bx
    sep #$20
    rtl
.endsub