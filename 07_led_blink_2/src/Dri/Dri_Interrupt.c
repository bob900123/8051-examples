#include <STC89C5xRC.h>
#include "Com_Utils.h"
#include "Dri_Interrupt.h"

#define FOSC 11059200 // 晶振頻率
#define NT   12       // 12 分頻
#define MAX_CALLBACK_COUNT 4

const unsigned int timer0_reload = 65536 - FOSC / NT / 1000;  // 1 ms
static Timer0_Callback timer0_callbacks[MAX_CALLBACK_COUNT];

void Dri_Timer0_Init()
{   
    unsigned char i;

    TR0 = 0; 

    EA = 1;   // 總開關
    ET0 = 1;  // 打開計時器中斷 0
    
    // GATE = 0, C/T = 0, M1 = 0, M0 = 1
    TMOD &= 0xF0;
    TMOD |= 0x01;
    
    // 初始值為 64614
    TH0 = timer0_reload >> 8;
    TL0 = timer0_reload & 0xFF;
    
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        timer0_callbacks[i] = NULL;
    }

    TR0 = 1;  // 運行暫存器
}

bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    // 註冊該函數
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (timer0_callbacks[i] == callback)
        {
            return 1; // 如果該函數被註冊過，直接返回
        }

        if (timer0_callbacks[i] == NULL)
        {
            timer0_callbacks[i] = callback;
            return 1;
        }
    }

    return 0;
}

bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (timer0_callbacks[i] == callback)
        {
            timer0_callbacks[i] = NULL;
            return 1;
        }
    }
    return 0;
}

void Dri_Timer0_Func() interrupt 1
{
    unsigned char i;

    TH0 = timer0_reload >> 8;
    TL0 = timer0_reload & 0xFF;

    // 調用所有的回呼函數
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (timer0_callbacks[i])
        {
           timer0_callbacks[i]();
        }
    }
}
