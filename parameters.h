#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loader.h"

#define VERTEX_PARAMETER "-v\0"
#define EDGE_PARAMETER "-e\0"
#define SOURCE_PARAMETER "-s\0"
#define TARGET_PARAMETER "-t\0"
#define OUT_PARAMETER "-out\0"
#define IS_VALID_PARAMETER "-a\0"

#define EXTENSION_LEN 4
#define CORRECT_EXTENSION ".csv\0"

#define DIRECTORY_PATH "data/\0"
#define UNDEFINED_PATH "undefined\0"
#define FILENAME_LEN 32

extern char out_path[];
extern char node_path[];                
extern char edge_path[]; 
extern int source_id;
extern int target_id;             
extern int is_valid; 

int format_check(char *name);

int parameters_processing(int argc, char *argv[]);

#endif
