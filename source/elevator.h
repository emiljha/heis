/**
 * @file elevator.h
 * @brief File that contains the elevator struct and basic elevator functions.
 * 
 */

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "hardware.h"
#include "timer.h"


#define ORDER_UP 0
#define ORDER_DOWN 1
#define ORDER_INSIDE 2
#define NUMBER_OF_ORDERS 3
#define TOP_FLOOR 3
#define BOTTOM_FLOOR 0

/**
 * @brief Enum used to define the different states of the elevator.
 */
typedef enum {
  IDLE,
  MOVE,
  EMERGENCY_STOP,
  DOOR_OPEN
} elevator_state_t;

/**
 * @brief Struct that describes the elevator. It contains all the important variables for the process
 */
typedef struct {
  elevator_state_t current_state;
  elevator_state_t last_state;
  int current_floor;
  int queue[HARDWARE_NUMBER_OF_FLOORS][NUMBER_OF_ORDERS];
  HardwareMovement current_dir;
  time_t time;
} elevator_t;

/**
 * @brief Function that controls all the lights in the elevator.
 * 
 * The function consist of a for loop that checks the order matrix and turns on the light is there is a order. It
 * also turns on the stop light when the stop button is pushed. 
 * @param elevator_t *e, pointer to a struct that contains all the information important for running the elevator.
  */
void elevator_lights(elevator_t *e);

/**
 * @brief Function that turns off all the outside and inside order lights. 
 * @param elevator_t *e, pointer to a struct that contains all the information important for running the elevator.
 */
void elevator_clear_all_lights();



#endif
