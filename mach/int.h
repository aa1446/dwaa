#ifndef DWAA_MACH_INT_H
#  define DWAA_MACH_INT_H

#  define DW_OPC_NOP (dw_mdat_t) 0x00
#  define DW_OPC_HLT (dw_mdat_t) 0xFF

#  include <stddef.h>
#  include <stdint.h>

typedef uint8_t dw_8bitd_t;
typedef uint64_t dw_64bitd_t;

typedef dw_8bitd_t dw_mdat_t;
typedef dw_64bitd_t dw_rdat_t;
typedef dw_64bitd_t dw_size_t;
typedef dw_64bitd_t dw_addr_t;

extern const dw_addr_t DW_REC_IDX;

#endif
