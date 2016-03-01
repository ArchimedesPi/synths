#ifndef __EFFECTS_H__
#define __EFFETCS_H__

#include "wavetables.h"

#define i16 int16_t
#define u8 uint8_t
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


#endif
