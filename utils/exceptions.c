//
// Created by Omar on 05/05/2024.
//

//#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void throwException(int errorCode, const char *errorMessage, const char *caller, const char *file, int line) {
    fprintf(stderr, "Error in %s();\nat file: %s\nat line: %d\nError code: %d\nError message: %s\n", caller, file, line,
            errorCode, errorMessage);
//    exit(errorCode);
}