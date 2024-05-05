cmake_minimum_required(VERSION 3.26)
project(CPU_Scheduling_Simulator C)

set(CMAKE_C_STANDARD 23)

add_executable(CPU_Scheduling_Simulator main.c
        models/process.h
        schedulers/schedulers.h
        models/process.c
        models/table.h
        models/table.c
        schedulers/schedulers.c
        collections/hashmap.h
        collections/mergeSort.h
        collections/priorityQueue.h
        collections/priorityQueue.c
        collections/compareFunctions.h
        collections/compareFunctions.h
        collections/compareFunctions.c
        models/ganttChart.c
        models/ganttChart.h
        models/ganttChart.h
        collections/linkedList.c
        collections/linkedList.h
        utils/exceptions.h
        utils/exceptions.c
)
