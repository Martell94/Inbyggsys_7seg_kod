#include "header.h"

/********************************************************************************
                            ISR (PCINT0_vect): 
   Avbrottsrutin. Hit kommer man när någon av knapparna tryckts ned. Först 
   har man en kort debounce, och sedan hoppar man beroende på tryckt knapp 
   till önskad rutin. 
********************************************************************************/
ISR (PCINT0_vect){
   disable_pin_change_interrupt(IO_PORTB);
   timer_enable_interrupt(&t0);
   
   if(button_is_pressed(&b1)){
      display_toggle_count();
   }
   if(button_is_pressed(&b2)){
      display_toggle_count_direction();
   }
   if(button_is_pressed(&b3)){
      display_toggle_output();
   }
}

/********************************************************************************
                            ISR (TIMER0_OVF_vect): 
           Timeravbrott. Används som debounce för knapptryckningar. 
********************************************************************************/
ISR (TIMER0_OVF_vect){
timer_count(&t0);
   if (timer_elapsed(&t0)){
      timer_disable_interrupt(&t0);
      enable_pin_change_interrupt(IO_PORTB);
   }
}

/********************************************************************************
                            ISR (TIMER1_COMPA_vect): 
   Avbrottsrutin. Avbrott sker var 0.128:e millisekund när timern är aktiverad.
   En gång i millisekunden togglas talet utskrivet på 7-segmentsdisplayerna 
   mellan tiotal och ental, för att ge intryck av att båda är igång samtidigt.
********************************************************************************/
ISR (TIMER1_COMPA_vect){
	display_toggle_digit();
   return;
}

/********************************************************************************
                            ISR (TIMER2_OVF_vect): 
Avbrottsrutin. Avbrott sker var 0.128:e millisekund när timern är aktiverad. 
En gång per sekund inkrementeras talet utskrivet på 7-segmentsdisplayerna.
********************************************************************************/
ISR (TIMER2_OVF_vect){
	display_count();
   return;
}
