#include <STC89C5xRC.h>
#include "Com_Utils.h"

volatile bit INT1_Flag = 0;

void Init_INT1()
{   
    EA = 1;   // 總開關
    EX1 = 1;  // 打開外部中斷 1
    IT1 = 1;  // 下降沿觸發
}

void INT1_Handler() interrupt 2
{
    INT1_Flag = 1;
}