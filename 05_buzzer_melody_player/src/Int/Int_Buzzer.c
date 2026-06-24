#include <STC89C5xRC.H>
#include "Com_Utils.h"

#define BUZZ P30

void Int_Buzzer_Buzz(int freq, int duration)
{
    unsigned int half_period;
    unsigned int cycle_count;
    unsigned int i;

    if (freq == 0) {
        BUZZ = 0;
        cycle_count = duration * 10;
        Com_Utils_Delay100us(cycle_count);
        return;
    }

    half_period = 5000 / freq;
    cycle_count = duration * 10 / (half_period * 2);

    for (i = 0; i < cycle_count; i++)
    {
        BUZZ = 1;
        Com_Utils_Delay100us(half_period);
        BUZZ = 0;
        Com_Utils_Delay100us(half_period);
    }
}