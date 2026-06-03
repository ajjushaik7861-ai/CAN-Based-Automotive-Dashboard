/*
 * File:   main.c
 * Author: ajjus
 *
 * Created on 6 May, 2026, 1:17 PM
 */

#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 20000000

#include "can.h"
#include "clcd.h"
#include "timer.h"
#include "message_handler.h"
#include "msg_id.h"
#include "uart.h"

uint16_t msg_id;
uint8_t data[8];
uint8_t len;

void init_config(void)
{
    ADCON1 = 0x0F;

    init_clcd();
    init_can();
    init_timer0();

    TRISBbits.TRISB0 = 0; // LED
    RB0 = 0;
}

void main(void)
{
    init_config();

    while(1)
    {
        process_canbus_data();
    }
}

