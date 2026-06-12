#include <STC89C5xRC.H>
#include "Int_Key.h"

#define LED P35

void main()
{

    while (1)
    {
        if (Int_Key_IsButton1Press())
        {
            LED = ~LED;
        }
    }
}
