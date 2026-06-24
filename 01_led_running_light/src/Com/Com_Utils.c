#include <INTRINS.H>

void Com_Utils_Delay1ms(int count) //@11.0592MHz
{
    unsigned char data i, j;
    while (count > 0)
    {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
