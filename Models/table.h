//
// Created by Omar on 01/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_TABLE_H
#define CPU_SCHEDULING_SIMULATOR_TABLE_H

#include <stdio.h>

typedef struct {
    char *name;
    int stringLength;
} tableInformation;

void printTableDivider(tableInformation *informationArray, int numberOfColumns);

void printTableHeader(char *header, tableInformation *informationArray, int numberOfColumns);

void printTable(char *header, tableInformation *informationArray, int numberOfColumns);

#endif //CPU_SCHEDULING_SIMULATOR_TABLE_H
