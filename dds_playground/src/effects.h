#ifndef __EFFECTS_H__
#define __EFFETCS_H__

#include "types.h"
#include "wavetables.h"
#include "stdlib.h"

#define N_WAVETABLES 6

#define EFFECT_ON(effect, effects) effects & effect

#define LFO (1 << 0)
struct Lfo {
    float rate;
    float p;
    u16 amp;
};

float update_lfo(Lfo *lfo) {
    lfo->p += lfo->rate;
    if (lfo->p > 1) lfo->p -= 2;
    return lfo->p * (1 - fabs(lfo->p));
}



#define ARPEGGIATOR (1 << 1)
struct Arpeggiator {
    u16 period;

    u8 pointer;
};
u8 arpeggiator_icon[] = {0x3,0x0,0x0,0xe,0x0,0x0,0x18,0x0};
#define ARPEGGIATOR_ICON (u8)0

inline void arp_init(Arpeggiator *arp) {
    arp->period = 0;
    
    arp->pointer = 0;
}

inline void arp_wts(Arpeggiator *arp, u8 active_wts) {
    arp->pointer++;
}


#endif
