#include "pushbutton.h"

void InitializePushButtonPortPin (void)
{
	// Configure port pin for pushbutton, including enabling
    // the port pin interrupt.
    P1DIR &= ~BIT3;
    P1REN |= BIT3;
    P1OUT |= BIT3;
    P1IES |= BIT3;
    P1IE |= BIT3;
}
