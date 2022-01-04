#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "edge.h"

typedef struct _node {
    int id;
    int color;
    int pred;
    char *wkt;
    vector_t *edges;
} node_t;


node_t *node_create(const int id, const char *wkt);


/**
 * @brief Funkce pro uvolnění osoby.
 * @param poor Uvolňována osoba.
 */
void node_destroy(node_t **poor);



#endif

