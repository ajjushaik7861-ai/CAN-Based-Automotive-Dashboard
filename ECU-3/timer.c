
#include <xc.h>
#include "timer.h"
#include "message_handler.h"

void init_timer0(void)
{
    T0CS = 0;
    PSA  = 0;
    //T0PS = 0b111;   // 1:256
    T0CONbits.T0PS = 0b111;  

    TMR0 = 6;

    TMR0IE = 1;
    GIE = 1;
}

void __interrupt() isr(void)
{
    static uint16_t count = 0;

    if (TMR0IF)
    {
        TMR0 = 6;
        TMR0IF = 0;

        count++;

        if (count >= 50)   // ~500ms
        {
            switch(led_state)
            {
                case LED_OFF:
                    RB0 = 0;
                    break;

                case LED_LEFT:
                case LED_RIGHT:
                case LED_HAZARD:
                    RB0 = !RB0;
                    break;
            }

            count = 0;
        }
    }
}