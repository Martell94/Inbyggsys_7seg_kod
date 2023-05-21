#include "header.h"

/********************************************************************************
                                     main: 
   Programmets huvudfunktion. Inneh�ller endast en watchdog reset-funktion,
   f�r att undvika att systemet fryser.
********************************************************************************/
int main(void){
   
   setup();
   
   while (1){
      wdt_reset();
   }
   
   return 0;
}

