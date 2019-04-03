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

int spin(float degrees, int power) {
    float target_position, overshoot, desired_position;
    int position;

    overshoot = DEGREES_OVERSHOOT_AT_FULL_POWER * abs(power) / 100;
    target_position = abs(degrees);
    printf("Target position: %8.1f\n", target_position);
    desired_position = target_position - overshoot;
    printf("minus overshoot: %8.1f\n", desired_position);

    set_create_total_angle(0);
    if (degrees > 0) {
        create_spin_CCW((int) (SPEED_AT_MAX_POWER * power / 100.0));
    } else {
        create_spin_CW((int) (SPEED_AT_MAX_POWER * power / 100.0));
    }
    while (TRUE) {
        position = get_create_total_angle();
        if (abs(position) >= desired_position) {
            create_stop();
            break;
        }
        if (SLEEP_MSECONDS_PER_ITERATION > 0) {
            msleep(SLEEP_MSECONDS_PER_ITERATION);
        }
    }

    msleep(1000);
    position = get_create_total_angle();
    printf("Actual position:  %6d\n", position);
   // press();
    return position;
}