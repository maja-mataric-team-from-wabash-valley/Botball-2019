#include <kipr/botball.h>
#include "utilities.h"
#include "create.h"
#include "camera.h"




extern int PRESS_A;

int create_main() {
    int rv=0, rv1=1, rv2=2, position;
    int NSport, Sport;
    int jawsOpen, jawsClosed;
    // int greyThresh, whiteThresh;
    // point2 center;
    PRESS_A = FALSE;
    jawsOpen = 700;
    jawsClosed = 1100;
    // greyThresh = 1000;
    // whiteThresh = 2000;
    start_create(); 
    camera_start();
    
    NSport = 0;
    Sport = 1;
    servo(0, jawsClosed);
    enable_servo(0);
        
    //Starts from starting block and gets food-medecine back to starting block
    //wait_for_light(5);
    //shut_down_in(118);
    CLeft(5,25);
    CForward(5,75);
    CLeft(2.5,25);
    CForward(25,75);
    
    while(rv != 1){
        rv = get_create_rbump();
        create_drive_direct(75, 80);
        msleep(20);
    }
    create_stop();
    CRight(15, 50);
    servo(0,jawsOpen);
 	msleep(300);
    follow_line(NSport, Sport);
    //PRESS_A = TRUE;
    servo(0, jawsClosed);
    CRight(5, 25);
    do{
        rv = find_tag(0);
        rv1 = find_tag(0);
   
    } while(rv != rv1);
        
        
    if(rv == 1){
        CLeft(1.5, 25);
        servo(0, jawsOpen);
        CBackward(18, 75);
        CForward(12, 30);
        servo(0, jawsClosed);
    }
    if(rv == 0){
        CRight(10, 25);
        servo(0, jawsOpen);
        CBackward(20, 75);
        CForward(12, 45);
        CLeft(12, 25);
        servo(0, jawsClosed);
    }
    PRESS_A = FALSE;
    position = rv;
    msleep(20);
    if(rv == 1){
        CRight(77, 25);
    } else {
        CRight(71, 25);
    }
    msleep(20);
    servo(0, jawsOpen);
    msleep(20);
    centered_movement(2, 7);
    msleep(20);
    servo(0, jawsClosed);
    CForward(12, 50);
    if(position == 1){
        CLeft(85,50);
        CBackward(10, 50);
        servo(0, jawsOpen);
        CForward(12, 50);
        servo(0, jawsClosed);
        CLeft(5, 50);
    }
    if(position == 0){
        CLeft(35, 50);
        CBackward(18, 15);
        servo(0, jawsOpen);
        CForward(18, 15);
        servo(0, jawsClosed);
        CLeft(55, 50);
    }
    CForward(16, 75);
    CRight(90, 50);
    servo(0, jawsOpen);
    centered_movement(2, 7);
    msleep(20);
    servo(0, jawsClosed);
    CForward(12, 50);
    CLeft(180, 50);
    CBackward(10, 50);
    servo(0, jawsOpen);
    CForward(15, 50);
    CLeft(90, 50);
    CBackward(14, 50);
    CLeft(90, 50);
    
    
      
    
    
    
    

    end_create();
    disable_servo(0);
    return 300;
}