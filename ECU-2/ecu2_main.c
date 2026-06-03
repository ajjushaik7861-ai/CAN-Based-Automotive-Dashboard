

#include <xc.h>
#include <stdint.h>


#include "adc.h"
#include "can.h"
#include "digital_keypad.h"
#include "msg_id.h"
#include "ecu2_sensor.h"
#include "uart.h"

uint16_t msg_id;
unsigned char len;
unsigned char data[8];

void init_config(void) {
    ADCON1 = 0x0F;

    init_adc();
    init_digital_keypad();
    init_can();
    init_uart();
}

void main(void) {
    //    TRISB = 0x00;      
    //    PORTB = 0x00;

    init_config();
    uint8_t rpm;
    IndicatorStatus state;
    uint8_t ind_data[1];
    while (1) {
        /* Prepare RPM */
        rpm = get_rpm();
        can_transmit(RPM_MSG_ID, &rpm, 1);
        for (int wait = 300; wait--;);

        //    rpm_buf[0] = (rpm / 1000) + '0';
        //    rpm_buf[1] = ((rpm / 100) % 10) + '0';
        //    rpm_buf[2] = ((rpm / 10) % 10) + '0';
        //    rpm_buf[3] = (rpm % 10) + '0';
        //    rpm_buf[4] = '\0';

        /* Prepare Indicator */
        state = process_indicator();

//        ind_data[0] = (uint8_t) state;

        /* Transmit both */

        can_transmit(INDICATOR_MSG_ID, &state, 1);
        for (int wait = 400; wait--;);
        /* Receive first message */
        //    while (!RXB0FUL);
        //    can_receive(&msg_id, data, &len);
        //
        //    if (msg_id == RPM_MSG_ID)
        //    {
        //        puts("RPM: ");
        //        data[len] = '\0';
        //        puts((char *)data);
        //        puts("\r\n");
        //    }
        //    else if (msg_id == INDICATOR_MSG_ID)
        //    {
        //        puts("IND: ");
        //        switch (data[0])
        //        {
        //            case 0: puts("OFF"); break;
        //            case 1: puts("LEFT"); break;
        //            case 2: puts("RIGHT"); break;
        //            case 3: puts("HAZARD"); break;
        //            default: puts("UNK"); break;
        //        }
        //        puts("\r\n");
        //    }

        /* Receive second message */
        //    while (!RXB0FUL);
        //    can_receive(&msg_id, data, &len);
        //
        //    if (msg_id == RPM_MSG_ID)
        //    {
        //        puts("RPM: ");
        //        data[len] = '\0';
        //        puts((char *)data);
        //        puts("\r\n");
        //    }
        //    else if (msg_id == INDICATOR_MSG_ID)
        //    {
        //        puts("IND: ");
        //        switch (data[0])
        //        {
        //            case 0: puts("OFF"); break;
        //            case 1: puts("LEFT"); break;
        //            case 2: puts("RIGHT"); break;
        //            case 3: puts("HAZARD"); break;
        //            default: puts("UNK"); break;
        //        }
        //        puts("\r\n");
        //    }


    }
}