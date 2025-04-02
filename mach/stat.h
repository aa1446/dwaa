#ifndef DWAA_MACH_STAT_H
#  define DWAA_MACH_STAT_H

#  include "int.h"

struct dw_mstat
{
    struct
    {
        dw_size_t size;
        dw_mdat_t *data;
    } ram;
};

extern int dw_mstart(const dw_size_t, struct dw_mstat *);
extern int dw_mstop(struct dw_mstat *);

#endif
