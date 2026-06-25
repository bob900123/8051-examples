#include <STC89C5xRC.h>
#include <stdio.h>
#include "Com_Utils.h"
#include "Dri_Interrupt.h"

#define BTN P33
#define LED P17

void main(void)
{
    Init_INT1();

    while (1) {
        if (INT1_Flag == 1) {
            INT1_Flag = 0;
            Com_Utils_Delay1ms(20);
            if (BTN == 0) {
                LED = ~LED;
                while (BTN == 0);
                Com_Utils_Delay1ms(20);
            }
        }

    }
}