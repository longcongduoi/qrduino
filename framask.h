#define BLOCKS1 (2)
#define BLOCKS2 (0)
#define DATAWID (78)
#define ECCWID (20)
#define WD (45)
#define WDB ((WD+7)/8)
#ifndef __AVR__
#define PROGMEM
#define memcpy_P memcpy
#define __LPM(x) *x
#else
#include <avr/pgmspace.h>
#endif
static const unsigned char framebase[] PROGMEM = {
0xfe,0x00,0x00,0x00,0x0b,0xf8,
0x82,0x00,0x00,0x00,0x12,0x08,
0xba,0x00,0x00,0x00,0x12,0xe8,
0xba,0x00,0x00,0x00,0x1a,0xe8,
0xba,0x00,0x0f,0x80,0x3a,0xe8,
0x82,0x00,0x08,0x80,0x02,0x08,
0xfe,0xaa,0xaa,0xaa,0xab,0xf8,
0x00,0x00,0x08,0x80,0x00,0x00,
0x02,0x00,0x0f,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x08,0x80,0x08,0x80,0x08,0x80,
0x0a,0x80,0x0a,0x80,0x0a,0x80,
0x08,0x80,0x08,0x80,0x08,0x80,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,
0x0a,0x00,0x00,0x00,0x00,0x00,
0x78,0x00,0x00,0x00,0x00,0x00,
0x9a,0x00,0x0f,0x80,0x0f,0x80,
0x00,0x80,0x08,0x80,0x08,0x80,
0xfe,0x00,0x0a,0x80,0x0a,0x80,
0x82,0x00,0x08,0x80,0x08,0x80,
0xba,0x00,0x0f,0x80,0x0f,0x80,
0xba,0x00,0x00,0x00,0x00,0x00,
0xba,0x00,0x00,0x00,0x00,0x00,
0x82,0x00,0x00,0x00,0x00,0x00,
0xfe,0x00,0x00,0x00,0x00,0x00,
};

static const unsigned char framask[] PROGMEM = {
0xff,0x80,0x00,0x00,0x3f,0xf8,
0xff,0x80,0x00,0x00,0x3f,0xf8,
0xff,0x80,0x00,0x00,0x3f,0xf8,
0xff,0x80,0x00,0x00,0x3f,0xf8,
0xff,0x80,0x0f,0x80,0x3f,0xf8,
0xff,0x80,0x0f,0x80,0x3f,0xf8,
0xff,0xff,0xff,0xff,0xff,0xf8,
0xff,0x80,0x0f,0x80,0x07,0xf8,
0xff,0x80,0x0f,0x80,0x07,0xf8,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x0f,0x80,0x0f,0x80,0x0f,0x80,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,
0xfe,0x00,0x00,0x00,0x00,0x00,
0xfe,0x00,0x00,0x00,0x00,0x00,
0xfe,0x00,0x0f,0x80,0x0f,0x80,
0xff,0x80,0x0f,0x80,0x0f,0x80,
0xff,0x80,0x0f,0x80,0x0f,0x80,
0xff,0x80,0x0f,0x80,0x0f,0x80,
0xff,0x80,0x0f,0x80,0x0f,0x80,
0xff,0x80,0x00,0x00,0x00,0x00,
0xff,0x80,0x00,0x00,0x00,0x00,
0xff,0x80,0x00,0x00,0x00,0x00,
0xff,0x80,0x00,0x00,0x00,0x00,
};
