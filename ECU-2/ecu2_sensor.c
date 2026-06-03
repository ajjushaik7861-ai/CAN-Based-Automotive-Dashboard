
#include <xc.h>
#include "ecu2_sensor.h"
#include "adc.h"
#include "digital_keypad.h"

unsigned int adc_value = 0;
unsigned int rpm = 0;

uint16_t get_rpm()
{
    adc_value = read_adc(RPM_ADC_CHANNEL);
    rpm = (adc_value  / 10.23);
    return rpm;
}

IndicatorStatus process_indicator()
{
    static IndicatorStatus state = e_ind_off;

    unsigned char key = read_digital_keypad(LEVEL);

    if (key == SWITCH1)
        state = e_ind_left;
    else if (key == SWITCH2)
        state = e_ind_right;
    else if (key == SWITCH3)
        state = e_ind_hazard;
    else if (key == SWITCH4)
        state = e_ind_off;

    return state;
}