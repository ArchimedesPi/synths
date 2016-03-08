#define BAUD 31250

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "util.h"
#include "mcp4921.h"
#include "oscillator.h"
#include "tuning.h"
#include "usart.h"

#define N_VOICES 1
Wavetable oscillator1[N_VOICES];
Wavetable oscillator2[N_VOICES];
enum Waveform oscillator1_wave = SINE_WAVE;
enum Waveform oscillator2_wave = NO_WAVE;


#include "midi.h"

int main() {
    set_bit(DDRB, PB0);
    set_bit(PORTB, PB0);
    spi_init();
    usart_init();

    for (int i=0; i<N_VOICES; i++) {
        wt_init(&oscillator1[i], wt_square3_data, WT_SQUARE3_LENGTH);
        oscillator1[0].increment = note_to_increment(69);
    }

    sampling_interrupt_init();
    sei();

    while (true) {
       u8 in_byte =  uart_getchar();
       midi_process_byte(in_byte);
    }

    return 0;
}

ISR(TIMER1_COMPA_vect) {
    u16 mixer = 0;
    mixer += get_wt_value(&oscillator1[0]);
    mixer += 128;
    mixer *= 16;
    dac_write(mixer);
}


inline void midi_note_on(u8 channel, u8 note, u8 velocity) {
    oscillator1[0].increment = note_to_increment(note);
}
