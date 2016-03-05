#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>

#include "util.h"


int main() {
    set_bit(DDRB, PB5);
    
    while(true) {
        set_bit(PORTB, PB5);
        _delay_ms(1000);
        clear_bit(PORTB, PB5);
        _delay_ms(1000);
    }

    return 0;
}
