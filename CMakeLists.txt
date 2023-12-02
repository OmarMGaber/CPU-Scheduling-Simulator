cmake_minimum_required(VERSION 3.26)
project(CPU_Scheduling_Simulator C)

set(CMAKE_C_STANDARD 23)

add_executable(CPU_Scheduling_Simulator main.c
        Models/process.h
        Schedulers/schedulers.h
        Models/process.c
        Models/table.h
        Models/table.c
        Schedulers/schedulers.c
        utilities.c
        utilities.h
)
