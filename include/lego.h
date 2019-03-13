#ifndef BOTBALL_2019_LEGO_H
#define BOTBALL_2019_LEGO_H

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 3

#defint MOTOR_FOR_TICKS  LEFT_MOTOR
#define TICKS_PER_DEGREE              7.6  // TODO: Find this empirically.
#define TICKS_OVERSHOOT_AT_100       10    // TODO: Find this empirically.
#define SLEEP_MSECONDS_PER_ITERATION 10    // TODO: Try 0 (no sleep).

#define MILLISECONDS_PER_DEGREE_AT_1500  100  // TODO: Find this empirically.
#define MILLISECONDS_OVERSHOOT_AT_1500   100  // TODO: Find this empirically.

#define GYRO_DEGREES_PER_DEGREE 1000

#endif //BOTBALL_2019_LEGO_H
