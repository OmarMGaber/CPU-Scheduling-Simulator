//
// Created by Omar on 06/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_COMPAREFUNCTIONS_H
#define CPU_SCHEDULING_SIMULATOR_COMPAREFUNCTIONS_H

typedef int (*CompareFunction)(const void *, const void *);

int greaterInt(const void *a, const void *b);

int greaterString(const void *a, const void *b);

int greaterFloat(const void *a, const void *b);

int greaterLongLong(const void *a, const void *b);

int greaterDouble(const void *a, const void *b);

int greaterShort(const void *a, const void *b);

int greaterChar(const void *a, const void *b);

int smallerInt(const void *a, const void *b);

int smallerString(const void *a, const void *b);

int smallerFloat(const void *a, const void *b);

int smallerLongLong(const void *a, const void *b);

int smallerDouble(const void *a, const void *b);

int smallerShort(const void *a, const void *b);

int smallerChar(const void *a, const void *b);

#endif //CPU_SCHEDULING_SIMULATOR_COMPAREFUNCTIONS_H
