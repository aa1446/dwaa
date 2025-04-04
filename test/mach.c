#include "../mach/int.h"
#include "../mach/stat.h"

#include <assert.h>

int main(void) {
    struct dw_mstat mstat;

    assert(dw_mstart(5, &mstat));
    
    mstat.ram.data[2] = DW_OPC_HLT;

    assert(*mstat.rps.idx == 0);

    dw_mstep(&mstat);

    assert(*mstat.rps.idx == 1);

    dw_mstep(&mstat);
    
    assert(*mstat.rps.idx == 2);

    dw_mstep(&mstat);

    assert(*mstat.rps.idx == 2);

    dw_mstep(&mstat);

    assert(*mstat.rps.idx == 2);

    mstat.ram.data[2] = DW_OPC_NOP;

    dw_mstep(&mstat);

    assert(*mstat.rps.idx == 3);

    dw_mstep(&mstat);

    assert(*mstat.rps.idx == 4);

    assert(dw_mstop(&mstat));

    return 0;
}
