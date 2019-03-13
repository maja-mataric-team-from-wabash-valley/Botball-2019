#include "utilities.h"
#include "lego.h"

extern int PRESS_A;

void lego_main() {
    PRESS_A = TRUE;

    forward(12, 100);
    backward(12, 100);
    left(90, 50);
    right(90, 50);

    /*set_servo_position(0, 1800);
    enable_servo(0);
    press();
    
    servo(0, 600);
    servo(0, 1800);
    servo(0, 600);*/
}