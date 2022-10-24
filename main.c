#include <msp430.h> 
#include "InterruptServiceRoutines.h"
#include "LED.h"
#include "timerA.h"
#include "pwm.h"

// Function prototypes
void ConfigureClockModule(void);

/**
 * main.c
 */
int main(void)
{
    // Stop the watchdog timer, and configure the clock module.
    WDTCTL = WDTPW + WDTHOLD;
    ConfigureClockModule();

    // Initialize port pins and hardware.
    InitializeLEDPortPins();
    ConfigureTimerA();
    InitializePushButtonPortPin();

    _enable_interrupts();
    //return 0;
    P1SEL |= RED_LED_BIT;
    P1SEL |= BIT5;
    while(1){
//        RED_LED_PORT |= RED_LED_BIT;
//        if(TA0CCR1 > TA0R){
//            RED_LED_PORT |= RED_LED_BIT;
//        }else{
//            RED_LED_PORT &= ~RED_LED_BIT;
//        }
    }
}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) using factory calibrations.
    DCOCTL  = CALDCO_FREQUENCY;
    BCSCTL1 = CALBC1_FREQUENCY;

    // Divide SMCLK
    BCSCTL2 |= SMCLK_DIVIDE;
}
