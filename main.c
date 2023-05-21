#include "header.h"

/********************************************************************************
                                     main: 
   Programmets huvudfunktion. Innehåller endast en watchdog reset-funktion,
   för att undvika att systemet fryser.
********************************************************************************/
int main(void){
   
   setup();
   
   while (1){
      wdt_reset();
   }
   
   return 0;
}

