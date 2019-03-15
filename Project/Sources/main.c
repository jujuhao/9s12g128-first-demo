#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

//#include "GPIO.h"


void main(void) {
  /* put your own code here */
  

 // GPIO_PinDirOut(GPIO_PORT_AD0,7);
	EnableInterrupts;
  
  GPIO_PinDirIn(1, 0);  //WIN_POWER_PB0

  for(;;) 
  
  {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
