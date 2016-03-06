#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>

#include "util.h"
#include "mcp4921.h"

int main() {
    spi_init();

    u16 accumulator = 0;
    while (1) {
        dac_write(accumulator);
        accumulator += 15;
    }

    return 0;
}
