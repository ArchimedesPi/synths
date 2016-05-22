#ifndef __BZMN_UTILS_H__
#define __BZMN_UTILS_H__

#include <stdint.h>
#include <stdbool.h>

// -- nice shorthand for c arithmetic types
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define i8 int8_t
#define i16 int16_t
#define i32 int32_t

// -- bit twiddling
//#define _BV(bit)                 (1 << bit)
#define set_bit(sfr, bit)      (_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr, bit)    (_SFR_BYTE(sfr) &= ~_BV(bit))
#define toggle_bit(sfr, bit)   (_SFR_BYTE(sfr) ^= _BV(bit))
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

#endif
