#define BAUD 31250

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "util.h"
#include "mcp4921.h"
#include "oscillator.h"
#include "usart.h"

#define N_VOICES 6
volatile Wavetable oscillator1[N_VOICES];
enum Waveform oscillator1_wave = SQUARE_WAVE;
u8 osc_pointer = 0;
u8 held_keys = 0;

u32 t = 0;

#include "midi.h"

int main() {
    set_bit(DDRB, PB0);
    set_bit(PORTB, PB0);
    spi_init();
    usart_init();

    for (int i=0; i<N_VOICES; i++) {
        wt_init(&oscillator1[i], wt_square3_data, WT_SQUARE3_LENGTH);
        //oscillator1[0].increment = note_to_increment(69);
    }

    wt_set_note(&oscillator1[0], 69);
    wt_set_note(&oscillator1[1], 71);

    sampling_interrupt_init();
    sei();

    while (true) {
        if (CHECK_BIT(UCSR0A, RXC0)) {
           //midi_process_byte(UDR0);
        }

        t++;
    }

    return 0;
}

ISR(TIMER1_COMPA_vect) {
    set_bit(PORTB, PB0);
    u16 mixer = 0;

    for (u8 i=0; i<2; i++)
        mixer += get_wt_value(&oscillator1[i]);

    mixer += 128;
    mixer /= 2;
    mixer *= 16;
    dac_write(mixer);
    clear_bit(PORTB, PB0);
}


inline void midi_note_on(u8 channel, u8 note, u8 velocity) {
}

inline void midi_note_off(u8 channel, u8 note, u8 velocity) {
}
