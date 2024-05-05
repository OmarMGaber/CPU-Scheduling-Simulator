//
// Created by Omar on 05/05/2024.
//

#ifndef CPU_SCHEDULING_SIMULATOR_PARSER_H
#define CPU_SCHEDULING_SIMULATOR_PARSER_H

#include "../collections/linkedList.h"
#include "../models/process.h"

/*
 * Parses the arguments from the command line.
 * Including argument validation and error handling for non-expected commands or files.
 * @param argc the number of arguments.
 * @param argv the arguments.
 * @return a linked list of the arguments.
 */
LinkedList* parseArguments(int argc, char *argv[]);

/*
 *
 */
void parseFile(const char *fileName);

/*
 * Parses the processes from the input file.
 * @return a fixed size array of processes.
 */
Process* parseProcesses();

#endif //CPU_SCHEDULING_SIMULATOR_PARSER_H
