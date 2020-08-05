/*
 * File:   keypad.c
 * Author: Elikarp
 *
 * Created on July 22, 2019, 6:29 AM
 */

#include "keypad.h"

char kbd_getc() {
   static char kbd_call_count;
   static __bit kbd_down;
   static char last_key;
   static char col;

   char kchar;
   char row;
   
   kchar='\0';
   if(++kbd_call_count>KBD_DEBOUNCE_FACTOR) {
       switch (col) {
         case 0   : TRIS_KP = ALL_PINS&~COL0;
                    LAT_KP = ~COL0&ALL_PINS;
                    break;
         case 1   : TRIS_KP = ALL_PINS&~COL1;
                    LAT_KP = ~COL1&ALL_PINS;
                    break;
         case 2   : TRIS_KP = ALL_PINS&~COL2;
                    LAT_KP = ~COL2&ALL_PINS;
                    break;
         case 3   : TRIS_KP = ALL_PINS&~COL3;
                    LAT_KP = ~COL3&ALL_PINS;
                    break;
       }
       if(kbd_down) {
         if((PORT_KP & ALL_ROWS) == ALL_ROWS) {
           kbd_down = 0;
           kchar = last_key;
           last_key = '\0';
         }
       } else {
          if((PORT_KP & ALL_ROWS) != ALL_ROWS) {
             if((PORT_KP & ROW0) == 0)
               row = 0;
             else if((PORT_KP & ROW1)==0)
               row = 1;
             else if((PORT_KP & ROW2)==0)
               row = 2;
             else if((PORT_KP & ROW3)==0)
               row = 3;
             last_key = KEYS[row][col];
             kbd_down = 1;
          } else {
             ++col;
             if(col==4)
               col=0;
          }
       }
      kbd_call_count=0;
   }
  TRIS_KP = ALL_PINS;
  return(kchar);
}
