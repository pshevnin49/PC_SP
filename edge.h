/**
 * @file edge.h
 * @author Pavel Shevnin
 * @brief Soubor reprezentujicí hranu grafu doprávní sítě pro vypočet maximalního toku
 * @version 1.1
 * @date 2021-12-19
 * 
 */
#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Struktura edge reprezentuje hranu grafu
 * 
 */
typedef struct _edge {
    
    int id;/*index hrany*/
    int source;/*index uzlu ze ktereho hrana vychazi*/
    int target;/*index uzlu kterym hrana konci*/
    int capacity;/*propustnost hrany*/
    int is_valid;/*je hrana validni, nebo neni (0 - 1)*/
    int flow;/*tok ktery hranou uz bezi, treba pro Ford Fulkerson algorithm*/
    char *wkt;/*wkt z csv souboru pro danou hranu*/

}edge_t;

/**
 * @brief @brief Funkce edge create přijimá parametry, a generuje novou hranu
 * 
 * 
 * @param id index hrany
 * @param source index uzlu ze ktereho hrana vychazi
 * @param target index uzlu kterym hrana konci
 * @param capacity propustnost hrany
 * @param is_valid je hrana validni, nebo neni (0 - 1)
 * @param wkt wkt z csv souboru pro danou hranu
 * @return vraci ukazatel na hranu 
 */
edge_t *edge_create(const int id, const int source, const int target, const int capacity, const int is_valid, const char *wkt);

/**
 * @brief Funkce pro uvolnění hrany
 * 
 * @param poor Uvolňovana hrana 
 */
void edge_destroy(edge_t **poor);

#endif
