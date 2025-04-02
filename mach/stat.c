#include "stat.h"

#include "int.h"

#include <stdint.h>
#include <stdlib.h>

int dw_mstart(const dw_size_t ram_size, struct dw_mstat *mstat) {
    dw_size_t i;

    for (i = 0; i < DW_RALENGTH; i += 1) {
        mstat->ra[i] = 0x0000000000000000;
    }

    mstat->ram.size = ram_size;
    mstat->ram.data = (dw_mdat_t*) calloc(mstat->ram.size, sizeof(dw_mdat_t));

    if (mstat->ram.data == NULL) return 0;

    return 1;
}

int dw_mstop(struct dw_mstat *mstat) {
    if (mstat->ram.data != NULL) {
        free(mstat->ram.data);

        return 1;
    } else return 0;
}
