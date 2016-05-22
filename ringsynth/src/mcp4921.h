#ifndef __MCP4921_H__
#define __MCP4921_H__

#include <avr/io.h>
#include "util.h"

#define SLAVE_SELECT clear_bit(PORTB, PB2)
#define SLAVE_DESELECT set_bit(PORTB, PB2)

inline void spi_init() {
    DDRB |= _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB5);
    SPCR = _BV(SPE) | _BV(MSTR);
    SPSR |= _BV(SPI2X); // 2x SPI speed
}

inline u8 spi_swap_byte(u8 data) {
    SPDR = data;
    loop_until_bit_is_set(SPSR, SPIF);
    return (SPDR);
}

/* dacwrite(u16 data)
 * writes a 12 bit value out to the dac.
 * note: `data` *is* u16 but gets truncated to 12 bits and loses 4 lsbs of precision.
 *
 * speed:
 *   bitbang: 8.8us
 *   hw spi: 4.2us (!!!)
 */

inline void dac_write(u16 data) {
    SLAVE_SELECT;
    data &= 0xfff; // truncate to 12 bits

    spi_swap_byte(_BV(4) | _BV(5) | (data >> 8));
    spi_swap_byte(data & 0x0ff);

    SLAVE_DESELECT;
}

#endif
