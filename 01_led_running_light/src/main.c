#include <stdio.h>
#include <STC89C5xRC.h>

#include "Com_Utils.h"

void main(void)
{
    unsigned char i = 0;

    while (1)
    {
        P1 = 0x01;
        for (i = 0; i < 5; i++)
        {
            Com_Utils_Delay1ms(100);
            P1 <<= 1;
        }
    }
}
