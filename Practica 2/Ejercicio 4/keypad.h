#ifndef XC_HEADER_KEYPAD_H
#define	XC_HEADER_KEYPAD_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <pic18f4550.h>

//
#define COL0 (1 << 4)
#define COL1 (1 << 5)
#define COL2 (1 << 6)
#define COL3 (1 << 7)

#define ROW0 (1 << 0)
#define ROW1 (1 << 1)
#define ROW2 (1 << 2)
#define ROW3 (1 << 3)

#define ALL_ROWS (ROW0|ROW1|ROW2|ROW3)
#define ALL_PINS (ALL_ROWS|COL0|COL1|COL2|COL3)
#define KBD_DEBOUNCE_FACTOR 55
#define TRIS_KP TRISB
#define LAT_KP LATB
#define PORT_KP PORTB


/*char const KEYS[4][4] = {{'1','2','3','A'},
                         {'4','5','6','B'},
                         {'7','8','9','C'},
                         {'*','0','#','D'}};
*/

char const KEYS[4][4] = {{'7','8','9','/'},
                         {'4','5','6','*'},
                         {'1','2','3','-'},
                         {'.','0','#','+'}};

char kbd_getc(void);

#endif