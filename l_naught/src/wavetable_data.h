#ifndef __WAVETABLE_DATA_H__
#define __WAVETABLE_DATA_H__

#include <avr/pgmspace.h>
#include "util.h"

const i8 wt_sine_data[256] PROGMEM = { 
	0, 3, 6, 9, 12, 15, 18, 21,
	24, 27, 30, 34, 37, 39, 42, 45,
	48, 51, 54, 57, 60, 62, 65, 68,
	70, 73, 75, 78, 80, 83, 85, 87,
	90, 92, 94, 96, 98, 100, 102, 104,
	106, 107, 109, 110, 112, 113, 115, 116,
	117, 118, 120, 121, 122, 122, 123, 124,
	125, 125, 126, 126, 126, 127, 127, 127,
	127, 127, 127, 127, 126, 126, 126, 125,
	125, 124, 123, 122, 122, 121, 120, 118,
	117, 116, 115, 113, 112, 110, 109, 107,
	106, 104, 102, 100, 98, 96, 94, 92,
	90, 87, 85, 83, 80, 78, 75, 73,
	70, 68, 65, 62, 60, 57, 54, 51,
	48, 45, 42, 39, 37, 34, 30, 27,
	24, 21, 18, 15, 12, 9, 6, 3,
	0, -4, -7, -10, -13, -16, -19, -22,
	-25, -28, -31, -35, -38, -40, -43, -46,
	-49, -52, -55, -58, -61, -63, -66, -69,
	-71, -74, -76, -79, -81, -84, -86, -88,
	-91, -93, -95, -97, -99, -101, -103, -105,
	-107, -108, -110, -111, -113, -114, -116, -117,
	-118, -119, -121, -122, -123, -123, -124, -125,
	-126, -126, -127, -127, -127, -128, -128, -128,
	-128, -128, -128, -128, -127, -127, -127, -126,
	-126, -125, -124, -123, -123, -122, -121, -119,
	-118, -117, -116, -114, -113, -111, -110, -108,
	-107, -105, -103, -101, -99, -97, -95, -93,
	-91, -88, -86, -84, -81, -79, -76, -74,
	-71, -69, -66, -63, -61, -58, -55, -52,
	-49, -46, -43, -40, -38, -35, -31, -28,
	-25, -22, -19, -16, -13, -10, -7, -4
};

const i8 wt_triangle_data[256] PROGMEM = { 
	0, 1, 3, 5, 7, 9, 11, 13,
	15, 17, 19, 21, 23, 25, 27, 29,
	31, 33, 35, 37, 39, 41, 43, 45,
	47, 49, 51, 53, 55, 57, 59, 61,
	63, 65, 67, 69, 71, 73, 75, 77,
	79, 81, 83, 85, 87, 89, 91, 93,
	95, 97, 99, 101, 103, 105, 107, 109,
	111, 113, 115, 117, 119, 121, 123, 125,
	127, 125, 123, 121, 119, 117, 115, 113,
	111, 109, 107, 105, 103, 101, 99, 97,
	95, 93, 91, 89, 87, 85, 83, 81,
	79, 77, 75, 73, 71, 69, 67, 65,
	63, 61, 59, 57, 55, 53, 51, 49,
	47, 45, 43, 41, 39, 37, 35, 33,
	31, 29, 27, 25, 23, 21, 19, 17,
	15, 13, 11, 9, 7, 5, 3, 1,
	0, -2, -4, -6, -8, -10, -12, -14,
	-16, -18, -20, -22, -24, -26, -28, -30,
	-32, -34, -36, -38, -40, -42, -44, -46,
	-48, -50, -52, -54, -56, -58, -60, -62,
	-64, -66, -68, -70, -72, -74, -76, -78,
	-80, -82, -84, -86, -88, -90, -92, -94,
	-96, -98, -100, -102, -104, -106, -108, -110,
	-112, -114, -116, -118, -120, -122, -124, -126,
	-128, -126, -124, -122, -120, -118, -116, -114,
	-112, -110, -108, -106, -104, -102, -100, -98,
	-96, -94, -92, -90, -88, -86, -84, -82,
	-80, -78, -76, -74, -72, -70, -68, -66,
	-64, -62, -60, -58, -56, -54, -52, -50,
	-48, -46, -44, -42, -40, -38, -36, -34,
	-32, -30, -28, -26, -24, -22, -20, -18,
	-16, -14, -12, -10, -8, -6, -4, -2
};

const i8 wt_square_data[256] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127
};

const i8 wt_square3_data[256] PROGMEM = { 
        0, 10, 20, 29, 39, 48, 57, 66,
        74, 82, 89, 96, 102, 107, 112, 116,
        119, 122, 124, 126, 127, 127, 127, 126,
        125, 124, 122, 121, 118, 116, 114, 111,
        109, 107, 104, 102, 100, 99, 97, 96,
        95, 95, 94, 94, 94, 95, 96, 97,
        98, 99, 101, 102, 104, 106, 108, 109,
        111, 112, 114, 115, 116, 117, 117, 118,
        118, 118, 117, 117, 116, 115, 114, 112,
        111, 109, 108, 106, 104, 102, 101, 99,
        98, 97, 96, 95, 94, 94, 94, 95,
        95, 96, 97, 99, 100, 102, 104, 107,
        109, 111, 114, 116, 118, 121, 122, 124,
        125, 126, 127, 127, 127, 126, 124, 122,
        119, 116, 112, 107, 102, 96, 89, 82,
        74, 66, 57, 48, 39, 29, 20, 10,
        0, -11, -21, -30, -40, -49, -58, -67,
        -75, -83, -90, -97, -103, -108, -113, -117,
        -120, -123, -125, -127, -128, -128, -128, -127,
        -126, -125, -123, -122, -119, -117, -115, -112,
        -110, -108, -105, -103, -101, -100, -98, -97,
        -96, -96, -95, -95, -95, -96, -97, -98,
        -99, -100, -102, -103, -105, -107, -109, -110,
        -112, -113, -115, -116, -117, -118, -118, -119,
        -119, -119, -118, -118, -117, -116, -115, -113,
        -112, -110, -109, -107, -105, -103, -102, -100,
        -99, -98, -97, -96, -95, -95, -95, -96,
        -96, -97, -98, -100, -101, -103, -105, -108,
        -110, -112, -115, -117, -119, -122, -123, -125,
        -126, -127, -128, -128, -128, -127, -125, -123,
        -120, -117, -113, -108, -103, -97, -90, -83,
        -75, -67, -58, -49, -40, -30, -21, -11
};

#endif
