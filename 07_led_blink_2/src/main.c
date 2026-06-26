#include <STC89C5xRC.h>
#include <stdio.h>
#include "Com_Utils.h"
#include "Dri_Interrupt.h"

#define LED P17

static unsigned int timer0_counter = 0;

void ToggleLED()
{
    timer0_counter++;

    if (timer0_counter >= 1000) {
        LED = ~LED;
        timer0_counter = 0;
    }
}

void main(void)
{
    Dri_Timer0_Init();
    Dri_Timer0_RegisterCallback(ToggleLED);

    while (1);
}