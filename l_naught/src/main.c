#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>

#include "util.h"
#include "mcp4921.h"

int main() {
    spi_init();

    while (1) {
        SLAVE_SELECT;
        spi_swap_byte(0xfa);
        SLAVE_DESELECT;
        _delay_ms(100);
    }

    return 0;
}
