#include "header.h"

button_t b1, b2, b3;
timer_t t0;

/********************************************************************************
                                    setup: 
     Initierar Watchdog-timer på 1024 ms samt sjusegmentsdisplayen. 
     System reset aktiveras också. 
********************************************************************************/
void setup(void){
   wdt_init(WDT_TIMEOUT_1024_MS);
   wdt_enable_interrupt();
   
   button_init(&b1, 11);
   button_init(&b2, 12);
   button_init(&b3, 13);
   button_enable_interrupt(&b1);
   button_enable_interrupt(&b2);
   button_enable_interrupt(&b3);
   
   timer_init(&t0, TIMER_SEL_0, 300);
   display_init();
   return;
}
