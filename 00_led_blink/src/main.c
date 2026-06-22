#include <INTRINS.H>
#include <STC89C5xRC.H>

void Delay1ms(unsigned int count) //@11.0592MHz
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

void main(void)
{
    while (1)
    {
        P15 = ~P15;
        Delay1ms(500);
    }
}
