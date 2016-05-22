#ifndef __AUDIOINTERRUPT_H__
#define __AUDIOINTERRUPT_H__

#include <avr/interrupt.h>
#include <avr/io.h>

#include "util.h"
#include "mcp4921.h"

#define SAMPLE_RATE 16384

u16 c = 0;

inline void audiointerrupt_init() {
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

ISR(TIMER1_COMPA_vect) {
    set_bit(PORTB, PB0);

    dac_write(c++);
    clear_bit(PORTB, PB0);
}

#endif
