#ifndef __OSCILLATOR_H__
#define __OSCILLATOR_H__

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "util.h"
#include "wavetable_data.h"

enum Waveform {
    SINE_WAVE,
    TRIANGLE_WAVE,
    NO_WAVE,
};


// -- wavetable stuff
#define WT_SINE_LENGTH 256
#define WT_TRIANGLE_LENGTH 256
#define WT_SQUARE3_LENGTH 256
#define WT_SQUARE_LENGTH 256

#define ACCUMULATOR_STEPS 2048
#define SAMPLE_RATE 8000 // Hz

typedef struct Wavetable {
    const i8 *data;
    u16 len;

    u32 pointer;
    u32 increment;
    u32 accumulator;

    u8 mul;
    bool decaying;
} Wavetable;

inline void wt_init(Wavetable *wt, const i8 *data, u16 len) {
    wt->data = data;
    wt->len = len;

    wt->pointer = 0; // start at the beginning of the sample
    wt->increment = 0; // start with the sample stopped
    wt->accumulator = 0; // zero the phase

    wt->mul = 16; // full volume
    wt->decaying = false;
}

inline i8 get_wt_value(Wavetable *wt) {
    i8 value = (i8)pgm_read_byte_near(wt->data + wt->pointer);
    
    wt->accumulator += wt->increment;
    wt->pointer += wt->accumulator / ACCUMULATOR_STEPS;
    wt->accumulator %= ACCUMULATOR_STEPS;
    wt->pointer %= wt->len; 

    return value;
}

inline void wt_reset(Wavetable *wt) {
    wt->pointer = 0;
    wt->increment = 0;
    wt->accumulator = 0;
    wt->mul = 16;
    wt->decaying = false;
}

// -- interrupts

// THIS USES TIMER1! DON'T USE IT ANYWHERE ELSE!
inline void sampling_interrupt_init() {
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;

    // set up count-until-clear mode
    set_bit(TCCR1B, WGM12);

    // sync to CPU clock (fast)
    set_bit(TCCR1B, CS10);

    // enable output-compare interrupt
    set_bit(TIMSK1, OCIE1A);
    
    OCR1A = F_CPU / SAMPLE_RATE - 1;
}

#endif
