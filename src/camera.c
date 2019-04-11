#include <kipr/botball.h>
#include "camera.h"
#include "create.h"

#define CENTER     80
#define GRIPLENGTH  2.5
#define KPLEFT   0.75
#define KPRIGHT  0.75
#define BASESPEED  20
#define CENTIMETERS_PER_INCH 2.54




float distance_inches(int channel)
{
    int i, j;
    int area, totalarea=0, areacount=0;
    int ocount;
    float guess, areasum=0;
    
    for(j=0;j<5;j++){
        totalarea = 0;
        camera_update();
        ocount = get_object_count(channel);
        for(i=0;i<ocount;i++){
            area = get_object_area(channel, i);
            totalarea += area;

        }
        areasum+=totalarea;
        if(totalarea == 0 && j == 3){
            return 0;
        }
        areacount++;
        printf("Average area: %6.2f, Trials: %4d\n", areasum/areacount, areacount);
        msleep(20);
    }
    if(areasum > 0.1){
        guess = sqrt(45000.0/(areasum/areacount));
        printf("%f\n", guess);
        return guess;
    }
        msleep(500);
    return 0;
}
int find_tag(int channel)
{
    int ocount;  
    point2 pt;

    camera_open_at_res(LOW_RES);
    camera_update();
    ocount = get_object_count(channel);
    if(ocount <= 0){
        return find_tag(channel);
    }
    pt = get_object_center(channel, 0);
    printf("%d\n", pt.x);
    if(pt.x > CENTER){
        printf("right\n");
        return 1;
    }  
    else {
        printf("left\n");
        return 0;
    }
}
int camera_start()
{
    int rv, i;
    rv = camera_open_at_res(LOW_RES);
    if(rv == 0){
        return camera_start();
    }
    for(i=0;i<20;i++){
        camera_update();
        msleep(20);
    }
    return rv;
}
int centered_movement(int channel, float distance)
{
    int ocount=0, i=0, j;
    float angle, target_position=0;
    point2 center1, average;
    printf("%d\n",5);
    printf("%d\n",6);
    set_create_distance(0);
    printf("%d\n",7);
    while(target_position <= distance){
        ocount = get_object_count(channel);
        if(ocount <= 0){
            create_drive_direct(-BASESPEED, -BASESPEED);
        } else {
            center1 = get_object_center(channel, 0);
            average.x = (center1.x);
            average.y = center1.y;
            angle = CENTER - average.x;
            printf("angle: %f average: %d\n", angle, average.x);
            create_drive_direct(-(BASESPEED + angle * KPLEFT), -(BASESPEED - angle * KPRIGHT));
        }
        msleep(20);
        j = get_create_distance();
        target_position = (.1 * abs(j)) / CENTIMETERS_PER_INCH;
    }
    return 1;
}
void turn_to(int channel)
{
    int ocount, i=0, j;
    float angle, target_position=0;
    point2 average;
    create_spin_CW(20);
    while(average.x <= CENTER){
        do{
            camera_update();
            ocount = get_object_count(channel);
            printf("ocount: %d\n", ocount);
            i++;
        } while(ocount <= 0 && i < 20);
        average = get_object_center(channel, 0);
        angle = average.x - CENTER;
        printf("angle: %f average: %d\n", angle, average.x);
    };
}






