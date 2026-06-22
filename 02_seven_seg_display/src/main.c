#include <STC89C5xRC.H>
#include <stdio.h>

#include "Com_Utils.h"
#include "Int_DigitalTube.h"

void main(void)
{
    while (1)
    {
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            Int_DigitalTube_ShowNumber(i);
            Com_Utils_Delay1ms(1000);
        }
    }
}
