
#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"

/* Display buffers */
static char speed[4] = "--";
static char gear[3] = "--";
static char rpm[5] = "----";

volatile unsigned char led_state = LED_OFF;
volatile unsigned char status = e_ind_off;

/* External CAN buffers */
extern uint16_t msg_id;
extern uint8_t data[8];
extern uint8_t len;
unsigned char arr[][3] = {"GR", "GN", "G1", "G2", "G3", "G4", "G5", "_C"};

/* -------- HANDLERS -------- */

void handle_speed_data(uint8_t *data, uint8_t len) {

    clcd_print("SPD:", LINE1(0));
    clcd_putch(*data / 100 + ' 0', LINE1(4));
    clcd_putch((*data / 10) % 10 + ' 0', LINE1(5));
    clcd_putch(*data % 10 + ' 0', LINE1(6));
}

void handle_gear_data(uint8_t *data, uint8_t len) {
    clcd_print("GR:", LINE2(0));
    clcd_print(arr[*data], LINE2(4));

}

void handle_rpm_data(uint8_t *data, uint8_t len) {
    clcd_print("RPM:", LINE1(9));
    uint16_t rpm = (*data)*60;
    clcd_putch(rpm / 1000 + ' 0', LINE1(12));
    clcd_putch((rpm / 100) % 10 + ' 0', LINE1(13));
     clcd_putch((rpm / 10) % 10 + ' 0', LINE1(14));
    clcd_putch(rpm % 10 + ' 0', LINE1(15));
}

void handle_indicator_data(uint8_t *data, uint8_t len) {
    clcd_print("IN:", LINE2(8));
//    if (strcmp(data, "e_ind_off") == 0) {
//        clcd_print("Off ", LINE2(11));
//        status = e_ind_off;
//    } else if (strcmp(data, "e_ind_left") == 0) {
//        clcd_print("<-- ", LINE2(11));
//        status = e_ind_left;
//    } else if (strcmp(data, "e_ind_right") == 0) {
//        clcd_print("-->", LINE2(11));
//        status = e_ind_right;
//    } else if (strcmp(data, "e_ind_hazard") == 0) {
//        clcd_print("<-->", LINE2(11));
//        status = e_ind_hazard;
//    }
    clcd_putch(*data + '0', LINE2(11));
}

/* -------- DISPLAY -------- */

/*static void update_display(void)
{
    clcd_print("SPD:", LINE1(0));
    clcd_print(speed, LINE1(5));

    clcd_print("RPM:", LINE1(9));
    clcd_print(rpm, LINE1(13));

    clcd_print("GR:", LINE2(0));
    clcd_print(gear, LINE2(4));

    clcd_print("IN:", LINE2(8));

    switch(status)
    {
        case 0: clcd_print("OFF ", LINE2(12)); break;
        case 1: clcd_print("LFT ", LINE2(12)); break;
        case 2: clcd_print("RGT ", LINE2(12)); break;
        case 3: clcd_print("HZD ", LINE2(12)); break;
        default: clcd_print("UNK ", LINE2(12)); break;
    }
}*/

/* -------- CAN PROCESS -------- */

void process_canbus_data(void) {

    can_receive(&msg_id, data, &len);

    switch (msg_id) {
        case SPEED_MSG_ID:
            handle_speed_data(data, len);
            break;

        case GEAR_MSG_ID:
            handle_gear_data(data, len);
            break;

        case RPM_MSG_ID:
            handle_rpm_data(data, len);
            break;

        case INDICATOR_MSG_ID:
            handle_indicator_data(data, len);
            break;
    }


}