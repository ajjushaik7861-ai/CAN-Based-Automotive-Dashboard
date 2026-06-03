

#include<xc.h>
#include "ecu1_sensor.h"
#include "adc_header.h"
#include "can_header.h"
#include "msg_id.h"
#include "uart.h"
#include "digtal_keypad.h"


unsigned char arr[][3]={"RG","NG","G1","G2","G3","G4","G5","CC"};
 static unsigned char gear_index = 0,flag = 0;
 unsigned int adc_value;
 unsigned int speed=0;
 char buff[3];
 unsigned char key;
 
 
uint16_t get_speed()
{
    //clcd_print("SPEED : ", LINE1(0));
    adc_value = read_adc(CHANNEL4);
    speed = adc_value / 10.23;
 
    return speed;
}

unsigned char get_gear_pos()
{
    key = read_digital_keypad(STATE_CHANGE);
   

        if(key == SWITCH1)   
        {
            if(flag){
                flag = 0;
                 gear_index = 0;
            }
            else{
            if(gear_index <6)
            {
                gear_index++;
            }
            }
        }
        else if(key == SWITCH2)  
        {
            if(flag){
                flag = 0;
                 gear_index = 0;
            }
            else{
                if(gear_index > 0)
                {
              gear_index--;
                }
            }
            
        }
        else if(key == SWITCH3)  
        {
            flag = 1;
            gear_index = 7;   
        }
 
    return gear_index;
}