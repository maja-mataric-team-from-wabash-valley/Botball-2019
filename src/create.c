#include "utilities.h"
#include "create.h"

void start_create() {
    printf("Connecting to the Create robot...");
    printf("If nothing happens, check that:\n");
    printf("  - the Create is turned on, and\n");
    printf("  - the Create is plugged into the Wallaby.\n");
    printf("\n");

    create_connect();
    create_full();  // So that the program continues even if the wheels go off the ground.

    printf("Connected!\n\n");
}

void end_create() {
    printf("Disconnecting from the Create robot...");

    create_disconnect();
    printf("Disconnected!");
}

int CForward(float inches, int power) {
    return create_forward(inches, power);
}

int CBackward(float inches, int power) {
    return CForward(-inches, power);
}

int CLeft(float degrees, int power) {
    return create_spin(degrees, power);
}

int CRight(float degrees, int power) {
    return CLeft(-degrees, power);
}

int create_spin(float degrees, int power) {
    float target_position, overshoot, desired_position;
    int position;

    overshoot = CREATE_DEGREES_OVERSHOOT_AT_FULL_POWER * abs(power) / 100;
    target_position = abs(degrees);
    printf("Target position: %8.1f\n", target_position);
    desired_position = target_position - overshoot;
    printf("minus overshoot: %8.1f\n", desired_position);

    set_create_total_angle(0);
    if (degrees > 0) {
        create_spin_CCW((int) (CREATE_SPEED_AT_MAX_POWER * power / 100.0));
    } else {
        create_spin_CW((int) (CREATE_SPEED_AT_MAX_POWER * power / 100.0));
    }
    while (TRUE) {
        position = get_create_total_angle();
        if (abs(position) >= desired_position) {
            create_stop();
            break;
        }
        if (CREATE_SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(CREATE_SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_create_total_angle();
    printf("Actual position:  %6d\n", position);
    press();
    return position;
}

int create_forward(float inches, int power) {
    float target_position, overshoot, desired_position;
    int position;

    overshoot = CREATE_INCHES_OVERSHOOT_AT_FULL_POWER * abs(power) / 100;
    target_position = 10 * abs(inches) * CENTIMETERS_PER_INCH;
    printf("Target position: %8.1f\n", target_position);
    desired_position = target_position - overshoot;
    printf("minus overshoot: %8.1f\n", desired_position);

    set_create_distance(0);
    if (inches > 0) {
        create_drive_straight((int) (CREATE_SPEED_AT_MAX_POWER * power / 100.0));
    } else {
        create_drive_straight((int) (-CREATE_SPEED_AT_MAX_POWER * power / 100.0));
    }
    while (TRUE) {
        position = get_create_distance();
        if (abs(position) >= desired_position) {
            create_stop();
            break;
        }
        if (CREATE_SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(CREATE_SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_create_total_angle();
    printf("Actual position:  %6d\n", position);
    press();
    return position;
}

void follow_line(int NSport, int Sport)
{
   int j, left, right;
   float target_position;
   set_create_distance(0);
    j=9999;
   while(target_position <= 52){
       left = analog(NSport);
       right = analog(Sport);
       if(left < 1250 && right < 1250){
           create_drive_direct(-30, -100);
       }
       else if(left >= 1250 && right < 1250){
           create_drive_direct(-100, -30);
       }
       else if(left < 1250 && right >= 1250){
           create_drive_direct(-100, -30);
       }
       else {
           create_drive_direct(-100, -110);
       }
       msleep(20);
       j = get_create_distance();
       target_position = (.1 * abs(j)) / CENTIMETERS_PER_INCH;
   }
    create_stop();
}
           
    
    