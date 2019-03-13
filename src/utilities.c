#include "../include/utilities.h"

int PRESS_A = FALSE;

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