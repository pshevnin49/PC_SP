/**
 * @file node.h
 * @author Pavel Shevnin
 * @brief Soubor reprezentujicí uzel grafu doprávní sítě pro vypočet maximalního toku
 * @version 1.3
 * @date 2022-01-05
 * 
 */
#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "edge.h"

/**
 * @brief Struktura _node
 * Přestavuje jeden uzel grafu, každy uzel obsahuje vector_t s hranama, které z tohoto uzlu vychází 
 */
typedef struct _node{
    int id; /** Index uzlu*/
    int color; /** Stav uzlu (WHITE, GREY, BLACK) slouží k označení uzlu při použití BFS algoritmu */
    int pred; /** Předchozí uzel při hledání cesty algoritmem BFS */
    char *wkt; /** Souřadníce uzlu z .csv souboru */
    vector_t *edges; /** vector_t obsahujicí hrany, které z tohoto uzlu vychazí*/
}node_t;

/**
 * @brief Alokuje paměť pro uzel, a vkladá jeho index a WKT
 * 
 * @param id index uzlu
 * @param wkt souřadníce
 * @return node_t* ukazatel na uzel
 */
node_t *node_create(const int id, const char *wkt);

/**
 * @brief Funkce pro uvolnění uzlu
 * @param poor Uvolňovány uzel
 */
void node_destroy(node_t **poor);

#endif

