//
// Created by Omar on 05/05/2024.
//

#ifndef CPU_SCHEDULING_SIMULATOR_EXCEPTIONS_H
#define CPU_SCHEDULING_SIMULATOR_EXCEPTIONS_H

#include <errno.h>

// Program error messages
#define OUT_OF_BOUNDS_ERROR_MESSAGE "Index out of bounds."
#define NULL_POINTER_ERROR_MESSAGE "Null pointer."
#define INVALID_ARGUMENT_ERROR_MESSAGE "Invalid argument."
#define MEMORY_ALLOCATION_ERROR_MESSAGE "Failed to allocate memory."

#define PRINT(HAMADA) printf("%s\n", #HAMADA)
#define ENSURE_NON_NULL(ARGUMENT) if ((ARGUMENT) == NULL) THROW_EXCEPTION(EINVAL, NULL_POINTER_ERROR_MESSAGE)
#define ENSURE_ALLOCATED_ELSE_REPORT_ERROR(ARGUMENT, ERROR_MESSAGE) if ((ARGUMENT) == NULL) THROW_EXCEPTION(ENOMEM, ERROR_MESSAGE)

#define THROW_EXCEPTION(ERROR_CODE, ERROR_MESSAGE) throwException(ERROR_CODE, ERROR_MESSAGE, __func__, __FILE__, __LINE__)

void throwException(int errorCode, const char *errorMessage, const char *caller, const char *file, int line);

#endif //CPU_SCHEDULING_SIMULATOR_EXCEPTIONS_H
