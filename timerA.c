#include "timerA.h"
#include "pwm.h"

void ConfigureTimerA(void)
{
  TA0CTL = (MC_0 | TACLR);     // Stop and clear the timer

  // PWM_PERIOD = TACCR0 + 1 => TACCR0 = PWM_PERIOD - 1 (see pwm.h)
  TA0CCR0 = 4999; // 4999 = 20ms
  TA0CCR1 = 249; // 249 = 1ms

  //TA0CTL |= TAIE; 	// Enable Timer A Interrupt Flag (TAIFG)
  TA0CCTL0 |= CCIE; 	// Enable TACCR0 Compare/Capture Interrupt Flag (CCIFG0)
  //TA0CCTL1 |= CCIE;	// Enable TACCR1 Compare/Capture Interrupt Flag (CCIFG1)
  TA0CCTL1 |= OUTMOD_7;

  // Start the timer in up mode, using the SMCLK and appropriate clock divide.
  TA0CTL |= (TASSEL_2 | TIMERA_CLOCK_DIVIDE | MC_1);
}

