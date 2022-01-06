/**
 * @file bfs.h
 * @author Pavel Shevnin
 * @brief Soubor obsahujicí BFS (prohledávaní do šiřky) který hleda cestu v grafu,  
 * @version 1.2
 * @date 2021-12-27
 * 
 */
#ifndef _BFS_H
#define _BFS_H

#include <stdio.h>
#include <math.h>
#include "node.h"
#include "edge.h"
#include "loader.h"
#include "vector.h"
#include "queue.h"

/** @brief bíla barva pro stav uzlu*/
#define WHITE 0
/** @brief šedá barva pro stav uzlu*/
#define GREY 1
/** @brief černá barva pro stav uzlu*/
#define BLACK 2
/** @brief reprezentáce nekonečná*/
#define O 1000000000

/**
 * @brief Funkce find_edge přijíma ukazatel na uzel a cele čislo indexu. A hledá mezí hran tohoto uzlu hranu,
 * která vedé do uzlu, který ma index "to"
 * 
 * @param node_from ukazatel na uzel odkud jde hrana
 * @param to index uzlu kám jde hrana
 * @return edge_t* ukazatel na hranu
 */
edge_t *find_edge(node_t *node_from, int to);

/**
 * @brief Přijíma jako parameter index uzlu, a hledá uzel s takovým indexem mezí uzly grafu. 
 * Pak vrací ukazatel na tento uzel
 * 
 * @param id index uzlu
 * @return node_t* ukazatel na nalezény uzel
 */
node_t *find_node(int id);

/**
 * @brief Přijíma dva indexy uzlů, a hledá mezí dva uzly existujicí cestu. Nalézenou cestu vkladá do fronty, a mnění stav uzlů
 * za šedy. Pak kdýž uzel odstraňuje ze fronty a přebárví na černo. 
 * 
 * @param start zdroj
 * @param target stok
 * @return int 0 pokud cesta nebyla nalezena, a 1 pokud byla.
 */
int bfs(int start, int target);

#endif