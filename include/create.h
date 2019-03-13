#ifndef BOTBALL_2019_CREATE_H
#define BOTBALL_2019_CREATE_H

#define SPEED_AT_MAX_POWER 500
#define DEGREES_OVERSHOOT_AT_FULL_POWER 20
#define SLEEP_MSECONDS_PER_ITERATION 0

void start_create();
void end_create();
int spin(float degrees, int power);
int forward(float inches, int power);

#endif //BOTBALL_2019_CREATE_H
