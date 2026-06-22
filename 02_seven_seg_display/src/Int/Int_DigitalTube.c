#include <STC89C5xRC.H>

unsigned char code display[10] = {
    0xE7,
    0x84,
    0xD3,
    0xD6,
    0xB4,
    0x76,
    0x77,
    0xC4,
    0xF7,
    0xF6,
};

void Int_DigitalTube_ShowNumber(unsigned char num)
{
    P1 = display[num];
}

//