#include <stdio.h>
#include <STC89C5xRC.h>

#include "Com_Utils.h"

#define LED_DB P1
#define LED_COUNT 5

void main(void)
{
    unsigned char i = 1;

    while (1)
    {
        LED_DB = i;

        Com_Utils_Delay1ms(100);
        i <<= 1;

        if (i >= (1 << LED_COUNT))
        {
            i = 1;
        }
    }
}
