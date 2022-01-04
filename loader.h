#ifndef _LOADER_H
#define _LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "vector.h"
#include "parameters.h"

/** @brief Používaný znak k oddělování hodnotu v CSV souboru. */
#define EDGE_CSV_DELIMETER ",\"\0"
#define NODE_CSV_DELIMETER ",\0"

#define EDGE_TABLE_FORMAT "id,source,target,capacity,isvalid,WKT\0"
#define NODE_TABLE_FORMAT "id,WKT\0"

#define EXIT_FAILURE_VERTEX 1
#define EXIT_FAILURE_EDGE 2
#define EXIT_FAILURE_SOURCE 3
#define EXIT_FAILURE_TARGET 4
#define EXIT_FAILURE_OUT 5
#define EXIT_FAILURE_NO_FLOW 6
#define EXIT_FAILURE_UNDEF 7

/** @brief Cesta do souboru s hodnotama neobsahuje nazev souboru*/
#define FILE_PATH "../data/\0"


/** @brief Velikost načítacího bufferu pro edge */
#define EDGE_CHAR_BUFFER_SIZE 4096
#define NODE_CHAR_BUFFER_SIZE 256

extern vector_t *indexes;
extern vector_t *nodes;

int is_dublicate(int id);

int node_loader(char *path);

int edge_loader(char *path, int is_valid);

int source_in_graph(int source);

int target_in_graph(int target);

#endif