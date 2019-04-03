#include "utilities.h"
#include "lego.h"

extern int PRESS_A;
#define SERVO_GATE 1 
#define SERVO_GATE_DOWN 180
#define SERVO_GATE_UP 1160
#define L_SERVO_ARM 0
#define R_SERVO_ARM 2
#define R_SERVO_ARM_DOWN 300 //WAS 270 
#define R_SERVO_ARM_UP 820
#define R_SERVO_ARM_START 1820
#define L_SERVO_ARM_DOWN 1860 //WAS 1820
#define L_SERVO_ARM_UP 1230
#define L_SERVO_ARM_START 230

void lego_main() {
    PRESS_A = TRUE;
    set_servo_position(R_SERVO_ARM,R_SERVO_ARM_DOWN);
    set_servo_position(L_SERVO_ARM,L_SERVO_ARM_DOWN);
    set_servo_position(SERVO_GATE,SERVO_GATE_DOWN);
    enable_servos();
    msleep(2000);
    press();
    
    // both_servos(R_SERVO_ARM, L_SERVO_ARM, R_SERVO_ARM_UP);
    // both_servos(R_SERVO_ARM, L_SERVO_ARM, R_SERVO_ARM_START);
    // both_servos(R_SERVO_ARM, L_SERVO_ARM, R_SERVO_ARM_DOWN);

    //servo(SERVO_GATE,SERVO_GATE_DOWN);
    forward(18.25, 100);  // was 26
    right(88, 50);
    servo(SERVO_GATE,SERVO_GATE_UP);
    forward(14.75, 100);
    msleep(1000);
    set_servo_position(SERVO_GATE,SERVO_GATE_DOWN);
    msleep(1000);
    right(40, 50); //was 100
    backward(2,200);  
    right(35, 100);
    forward(8, 100);
    right(30, 100);
    forward(13, 100);
    return;
    //forward(13,200);  // rest were 13
    //forward(13, 200);
    //forward(13,200);
    //forward(13, 200);
    //forward(4,200);
    //left(30,200);
    /*
    PLAN FOR MOVEMENT - based on small robot
    f 26
    r 90
    f 13
    r 90
    b 2
    lower basket
    f 4
    sweep
    (f 13
    sweep)x4
    basket up
    f 4
    l 30

    l = left
    r = right
    f = forward
    b = backward


    */


    //forward(26, 100); right(90, 100)

    /*set_servo_position(0, 1800);
    enable_servo(0);
    press();

    servo(0, 600);
    servo(0, 1800);
    servo(0, 600);*/
}