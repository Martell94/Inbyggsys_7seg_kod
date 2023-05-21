#include "header.h"

/********************************************************************************
                            ISR (PCINT0_vect): 
   Avbrottsrutin. Hit kommer man n�r n�gon av knapparna tryckts ned. F�rst 
   har man en kort debounce, och sedan hoppar man beroende p� tryckt knapp 
   till �nskad rutin. 
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
           Timeravbrott. Anv�nds som debounce f�r knapptryckningar. 
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
   Avbrottsrutin. Avbrott sker var 0.128:e millisekund n�r timern �r aktiverad.
   En g�ng i millisekunden togglas talet utskrivet p� 7-segmentsdisplayerna 
   mellan tiotal och ental, f�r att ge intryck av att b�da �r ig�ng samtidigt.
********************************************************************************/
ISR (TIMER1_COMPA_vect){
	display_toggle_digit();
   return;
}

/********************************************************************************
                            ISR (TIMER2_OVF_vect): 
Avbrottsrutin. Avbrott sker var 0.128:e millisekund n�r timern �r aktiverad. 
En g�ng per sekund inkrementeras talet utskrivet p� 7-segmentsdisplayerna.
********************************************************************************/
ISR (TIMER2_OVF_vect){
	display_count();
   return;
}
