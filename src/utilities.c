#include <kipr/botball.h>
#include "utilities.h"

int PRESS_A = FALSE;

void servo(int port, int desired_position) {
    int current_position;
    
    current_position = get_servo_position(port);
    
    if (desired_position > current_position) {
        while (TRUE) {
            if (current_position >= desired_position) {
                set_servo_position(port, desired_position);
                break;
            }
            current_position = current_position + 2;
            set_servo_position(port, current_position);
            msleep(5);
        }
    } else {
        while (TRUE) {
            if (current_position <= desired_position) {
                set_servo_position(port, desired_position);
                break;
            }
            current_position = current_position - 2;
            set_servo_position(port, current_position);
            msleep(5);
        }
    }
    press();
}

void both_servos(int port1, int port2, int desired_position1) {
    int current_position1, current_position2;
    
    current_position1 = get_servo_position(port1);
    current_position2 = get_servo_position(port2);
    
    if (desired_position1 > current_position1) {
        while (TRUE) {
            if (current_position1 >= desired_position1) {
                break;
            }
            current_position1 = current_position1 + 1;
            current_position2 = current_position2 - 1;
            set_servo_position(port1, current_position1);
            set_servo_position(port2, current_position2);
            msleep(5);
        }
    } else {
        while (TRUE) {
            if (current_position1 <= desired_position1) {
                break;
            }
            current_position1 = current_position1 - 1;
            current_position2 = current_position2 + 1;
            set_servo_position(port1, current_position1);
            set_servo_position(port2, current_position2);
            msleep(5);
        }
    }
    press();
}

void move_servo(int start, int change, int finish, int delay, int servo, int ud)
{
   int i;
    
   for(i = start;(i*ud)<=(finish*ud);i+=change){
     set_servo_position(servo,i);
     msleep(delay);
   }
}

void press_a_to_continue() {
    if (! PRESS_A) {
        msleep(MILLISECONDS_FOR_PRESS_A);
        return;
    }

    printf("Press A to continue...\n");
    while (! a_button()) {}
    printf("Pressed!  Hands off!\n");
    while (a_button()) {}
    msleep(MILLISECONDS_FOR_HANDS_OFF);
}

void press() { press_a_to_continue(); }