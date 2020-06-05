#include <qc_base.h>


__qc_op_name(_UInt8,add):
__qc_op_name(_Int8,add):
    txa
    sty __al
    add __al
    rtl


__qc_op_name(_UInt8,sub):
__qc_op_name(_Int8,sub):
    txa
    sty __al
    sub __al
    rtl

__qc_op_name(_UInt16,add):
__qc_op_name(_Int16,add):
    rep #$20
    .m16
    txa
    sty __al
    add __al
    rtl
