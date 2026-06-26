#ifndef __DRI_INTERRUPT_H__
#define __DRI_INTERRUPT_H__

typedef void (*Timer0_Callback)(void);

void Dri_Timer0_Init();
bit Dri_Timer0_RegisterCallback(Timer0_Callback);
bit Dri_Timer0_DeregisterCallback(Timer0_Callback);

#endif /* __DRI_INTERRUPT_H__ */