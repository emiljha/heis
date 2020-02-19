
#include "fsm_elevator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

hardware_command_order_light(1, HARDWARE_ORDER_DOWN, 0);
hardware_command_order_light(2, HARDWARE_ORDER_DOWN, 0);
hardware_command_order_light(3, HARDWARE_ORDER_DOWN, 0);

hardware_command_order_light(0, HARDWARE_ORDER_UP, 0);
hardware_command_order_light(1, HARDWARE_ORDER_UP, 0);
hardware_command_order_light(2, HARDWARE_ORDER_UP, 0);

elevator_t elev;
elevator_t *e = &elev;
elevator_driver_init_floor(e);
e->current_state = IDLE;
for(int floor = 0; floor < 4; floor++) {
  for (int order = 0; order < 2; order ++) {
    e->queue[floor][order] = 0;
  }
}
elevator_go(e);
for(int floor = 0; floor < 4; floor++) {
  for (int order = 0; order < 2; order ++) {
    printf("%d \n", e->queue[floor][order]);
  }}


}
