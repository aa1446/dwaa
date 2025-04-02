#ifndef DWAA_MACH_STAT_H
#  define DWAA_MACH_STAT_H

#  define DW_RALENGTH (dw_size_t) 255

#  include "int.h"

struct dw_mstat {
    dw_rdat_t ra[DW_RALENGTH];
    struct {
        dw_rdat_t *idx;
    } rps;
    struct {
        dw_size_t size;
        dw_mdat_t *data;
    } ram;
};

extern int dw_mstart(const dw_size_t, struct dw_mstat*);
extern int dw_mstop(struct dw_mstat*);

extern void dw_mstep(struct dw_mstat*);

#endif
