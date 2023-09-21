/*
 * Interface_KeyBad.h
 *
 * Created: 9/9/2023 12:52:55 PM
 *  Author: m2010
 */ 


#ifndef INTERFACE_KEYBAD_H_
#define INTERFACE_KEYBAD_H_

#include "types.h"
#include "Configure_KeyBad.h"
#include "Dio_Int.h"
#include <util/delay.h>

#define NOT_PRESSED 255

/*KPD INIT*/
void Keypad_VidInit(void);
/*KPD Get pressed*/
u8 Keypad_U8GetKeyPressed(void);

// 
// #define N_Col 4
// #define N_Row 4
// #define NO_KEY 'T'
// 
// 
// void KeypadInit();
// u8 KeyPadGetKey();


#endif /* INTERFACE_KEYBAD_H_ */