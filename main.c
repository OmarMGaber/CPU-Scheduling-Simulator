#include <stdio.h>
#include <string.h>
#include "Models/process.h"
#include "Schedulers/schedulers.h"
#include "utilities.h"
#include "Collections/priorityQueue.h"

// Compare function for char arrays
int compareChar(const void *a, const void *b) {
    return (*(char *) a - *(char *) b);
}

int main() {

    PriorityQueue *pqGreater = createPriorityQueue(greaterInt);
    PriorityQueue *pqSmaller = createPriorityQueue(smallerInt);
    int arr[] = {10, 7, 8, 9, 1, 5};

    for (int i = 0; i < getArrayLength(arr); ++i) {
        push(pqGreater, &arr[i]);
        push(pqSmaller, &arr[i]);
    }

    printf("pqGreater: ");
    for (int i = 0; i < getArrayLength(arr); ++i) {
        printf("%d ", *(int *) top(pqGreater));
        pop(pqGreater);
    }

    printf("\npqSmaller: ");
    for (int i = 0; i < getArrayLength(arr); ++i) {
        printf("%d ", *(int *) top(pqSmaller));
        pop(pqSmaller);
    }


    return 0;
}
