#include "compareFunctions.h"
#include <string.h>

//#define MOD 1000000007

int smallerInt(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int greaterInt(const void *a, const void *b) {
    return -smallerInt(a, b);
}

int smallerFloat(const void *a, const void *b) {
    if (*(float *) a - *(float *) b < 0)
        return -1;
    if (*(float *) a - *(float *) b > 0)
        return 1;
    return 0;
}

int greaterFloat(const void *a, const void *b) {
    return -smallerFloat(a, b);
}

int smallerDouble(const void *a, const void *b) {
    if (*(double *) a - *(double *) b < 0)
        return -1;
    if (*(double *) a - *(double *) b > 0)
        return 1;
    return 0;
}

int greaterDouble(const void *a, const void *b) {
    return -smallerDouble(a, b);
}

int smallerLongLong(const void *a, const void *b) {
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}

int greaterLongLong(const void *a, const void *b) {
    return -smallerLongLong(a, b);
}

int smallerShort(const void *a, const void *b) {
    return *(short *) a - *(short *) b;
}

int greaterShort(const void *a, const void *b) {
    return -smallerShort(a, b);
}

int smallerChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int greaterChar(const void *a, const void *b) {
    return -smallerChar(a, b);
}

int smallerString(const void *a, const void *b) {
    return strcmp((char *) a, (char *) b);
}

int greaterString(const void *a, const void *b) {
    return -smallerString(a, b);
}
