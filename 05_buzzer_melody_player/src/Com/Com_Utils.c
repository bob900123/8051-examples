#include <INTRINS.H>

void Com_Utils_Delay100us(int count) //@11.0592MHz
{
    unsigned char data i;

    while (count > 0)
    {
        _nop_();
        i = 43;
        while (--i);
        count--;
    }
}
