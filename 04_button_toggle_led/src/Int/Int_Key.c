#include <STC89C5xRC.H>
#include "Com_Utils.h"

#define KEY P32

bit Int_Key_IsButton1Press()
{
    if (KEY == 0)
    {
        Com_Utils_Delay1ms(10);
        if (KEY == 0)
        {
            while (KEY == 0)
                ;
            return 1;
        }
    }
    return 0;
}
