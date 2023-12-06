//
// Created by Omar on 01/12/2023.
//

#include <stdio.h>
#include "utilities.h"

int getAndValidateUserInput(char *requestMessage, char *errorMessage, int lowerBound, int upperBound) {
    int input;
    if (requestMessage != NULL)
        printf("%s\n", requestMessage);
    while (scanf("%d", &input) != 1 || input < lowerBound || input > upperBound) {
        printf("%s\n", errorMessage);
        while (getchar() != '\n');
    }
    return input;
}