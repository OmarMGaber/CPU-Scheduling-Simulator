//
// Created by Omar on 01/12/2023.
//

#include <stdio.h>
#include "table.h"

void printTableDivider(tableInformation *informationArray, int numberOfColumns) {
    printf("+");
    for (int i = 0; i < numberOfColumns; ++i) {
        for (int j = 0; j < informationArray[i].stringLength + 2; ++j) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

void printTableHeader(char* header, tableInformation *informationArray, int numberOfColumns) {
    printf("%s: \n", header);
    printTableDivider(informationArray, numberOfColumns);
    printf("|");
    for (int i = 0; i < numberOfColumns; ++i) {
        printf(" %*s |", informationArray[i].stringLength, informationArray[i].name);
    }
    printf("\n");
    printTableDivider(informationArray, numberOfColumns);
}

void printTable(char* header, tableInformation *informationArray, int numberOfColumns) {
    printTableDivider(informationArray, numberOfColumns);
    printTableHeader(header, informationArray, numberOfColumns);
}