/* 
 * File:   message_handler.h
 * Author: ajjus
 *
 * Created on 6 May, 2026, 1:05 PM
 */

#ifndef MESSAGE_HANDLER_H
#define	MESSAGE_HANDLER_H


#include <stdint.h>

/*LED states */
#define LED_OFF     0
#define LED_LEFT    1
#define LED_RIGHT   2
#define LED_HAZARD  3

/* Indicator states */
typedef enum
{
    e_ind_off = 0,
    e_ind_left,
    e_ind_right,
    e_ind_hazard
} IndicatorStatus;

extern volatile unsigned char led_state;

void process_canbus_data(void);


#endif	/* MESSAGE_HANDLER_H */

