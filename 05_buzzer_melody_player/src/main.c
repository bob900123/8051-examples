#include "Int_Buzzer.h"
#include "Com_Utils.h"
#include <STC89C5xRC.H>
#include <intrins.h>

#define NOTE_REST 0

#define NOTE_DO 261
#define NOTE_RE 294
#define NOTE_MI 330
#define NOTE_FA 349
#define NOTE_SO 392
#define NOTE_LA 440
#define NOTE_SI 494

#define BEAT 490

int code music_twinkle_twinkle[] = {
    NOTE_DO, NOTE_DO, NOTE_SO, NOTE_SO,
    NOTE_LA, NOTE_LA, NOTE_SO, NOTE_REST,

    NOTE_FA, NOTE_FA, NOTE_MI, NOTE_MI,
    NOTE_RE, NOTE_RE, NOTE_DO, NOTE_REST,

    NOTE_SO, NOTE_SO, NOTE_FA, NOTE_FA,
    NOTE_MI, NOTE_MI, NOTE_RE, NOTE_REST,

    NOTE_SO, NOTE_SO, NOTE_FA, NOTE_FA,
    NOTE_MI, NOTE_MI, NOTE_RE, NOTE_REST,

    NOTE_DO, NOTE_DO, NOTE_SO, NOTE_SO,
    NOTE_LA, NOTE_LA, NOTE_SO, NOTE_REST,

    NOTE_FA, NOTE_FA, NOTE_MI, NOTE_MI,
    NOTE_RE, NOTE_RE, NOTE_DO, NOTE_REST
};

void main()
{   
    int i = 0; 
    while (1)
    {
        for (i = 0; i < 48; i++) {
            Int_Buzzer_Buzz(music_twinkle_twinkle[i], BEAT);
            Com_Utils_Delay100us(100);
        }
        Com_Utils_Delay100us(10000);
    }
}
