
#include <xc.h>
#include <stdint.h>
//#define _XTAL_FREQ 20000000

#include "adc_header.h"
#include "can_header.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"
#include "digtal_keypad.h"

//configurations calls

static void init_config(void) {
    ADCON1 = 0x0F;
    init_adc();
    init_digital_keypad();
//    init_uart();
    init_can();
    // init_clcd();

}

//Global buffers for CAN receive 
uint16_t msg_id;
unsigned char data;
unsigned char len;

//Gear strings 


int main(void) {
    init_config();

    char buff[4];
    unsigned char gear;
    while (1) {
        //for the speed
        uint8_t speed = get_speed();

        

        // SPEED
        can_transmit(SPEED_MSG_ID, &speed, 1);
     
        for(int i = 100; i--;);

//        can_receive(&msg_id, data, &len);
//        if (len > 0) {
//            puts("Speed: ");
//            data[len] = '\0';
//            puts((char *) data);
//            puts("\r\n");
//        }

       // GEAR
         gear = get_gear_pos();
        can_transmit(GEAR_MSG_ID, &gear, 1);
        for(int i = 200; i--;);

//       can_receive(&msg_id, data, &len);
//        if (len > 0) {
//            puts("Gear: ");
//            data[len] = '\0';
//            puts((char *) data);
//            puts("\r\n");
//        }
        
    }
}