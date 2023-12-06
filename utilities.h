//
// Created by Omar on 01/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_UTILITIES_H
#define CPU_SCHEDULING_SIMULATOR_UTILITIES_H

#include <stdio.h>
#include "Models/process.h"

//typedef enum {
//    False = 0, True = 1
//} boolean;


// program constants
#define MAX_NUMBER_OF_PROCESSES 200
#define MAX_ARRIVAL_TIME 1e5
#define MAX_BURST_TIME 1e5
#define MAX_PRIORITY 1e5
#define MAX_QUANTUM 1e5

// program error codes
#define INVALID_NUMBER_OF_PROCESSES (-1)
#define INVALID_ARRIVAL_TIME (-2)
#define INVALID_BURST_TIME (-3)
#define INVALID_PRIORITY (-4)
#define INVALID_QUANTUM (-5)
#define INVALID_INPUT (-6)

// program function-like macros
#define getArrayLength(ARRAY) ((sizeof (ARRAY))/(sizeof *(ARRAY)))
#define MAX(a, b) ((a > b)? a : b)
#define MIN(a, b) ((a > b)? a : b)

int getAndValidateUserInput(char *requestMessage, char *errorMessage, int lowerBound, int upperBound);

#endif //CPU_SCHEDULING_SIMULATOR_UTILITIES_H
