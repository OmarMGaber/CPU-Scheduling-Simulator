cmake_minimum_required(VERSION 3.26)
project(CPU_Scheduling_Simulator C)

set(CMAKE_C_STANDARD 23)

add_executable(CPU_Scheduling_Simulator main.c
        process.h
        schedulers.h
        process.c
        table.h
        table.c
        Schedulers/schedulers.c
        utilities.c
        utilities.h
)
