#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "util.h"
#include "mcp4921.h"
#include "audiointerrupt.h"

int main() {
    set_bit(DDRB, PB0);
    set_bit(PORTB, PB0);

    spi_init();
    audiointerrupt_init();
    sei();

    while (true) {
    }

    return 0;
}
