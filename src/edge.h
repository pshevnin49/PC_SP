
#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief 
 * 
 */
typedef struct _edge {
    
    int id;
    int source;
    int target;
    int capacity;
    int is_valid;
    int flow;
    char *wkt;

}edge_t;


edge_t *edge_create(const int id, const int source, const int target, const int capacity, const int is_valid, const char *wkt);

void edge_destroy(edge_t **poor);

void edge_print(const edge_t *p);

#endif
