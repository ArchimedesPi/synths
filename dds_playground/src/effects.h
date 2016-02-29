#ifndef __EFFECTS_H__
#define __EFFETCS_H__

#define i16 int16_t
#define u8 uint8_t

#define EFFECT_ON(effect, effects) effects & effect

#define EFFECT_BITCRUSHER 0x01


#define EFFECT_BITCRUSHER_ICON (u8)0
u8 effect_bitcrusher_icon[] = {
    1,1,1,31,16,16,16,0
};


inline i16 effect_bitcrusher(i16 input, u8 keepBits) {
    return (input & (-1 << (16 - keepBits)));
}

#endif
