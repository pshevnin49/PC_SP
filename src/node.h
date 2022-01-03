#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef struct _node {
    int id;
    int color;
    int pred;
    char *wkt;
    vector_t *edges;//change
} node_t;


node_t *node_create(const int id, const char *wkt);// vector_t is added


/**
 * @brief Funkce pro uvolnění osoby.
 * @param poor Uvolňována osoba.
 */
void node_destroy(node_t **poor);

/**
 * @brief Funkce vytiskne osobu do konzole.
 * @param p Tištěná osoba.
 */
void node_print(const node_t *node);

#endif

