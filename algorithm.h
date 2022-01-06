/**
 * @file algorithm.h
 * @author Pavel Shevnin
 * @brief Soubor obsahuje všechno pro hledání maximalního toku sítě v grafu pomocí 
 * Ford-Fulkerson algoritmus. Take v tomto souboru se ukladají hrany minimalního řezu do vectoru, aby na koncí běhu programu, v případě když 
 * parameter -out bude zadán uživatelem vypsát hrany minímalního řezu do souboru .csv
 * @version 1.0
 * @date 2021-12-25
 * 
 */
#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <stdio.h>
#include <math.h>
#include "node.h"
#include "edge.h"
#include "loader.h"
#include "vector.h"
#include "bfs.h"

/** @brief vector slouží k zapisu hran minimalního řezu*/
extern vector_t *out_edges;

/**
 * @brief Přijíma zdroj a stok, a pokud zdroj a stok jsou ruzná čísla provádí vypočet maximalního toku mezí těmito dvěma uzly. Pokud jsou stejná, vrací 0(tok určítě nebude nalezén)
 * Na začátku každa hrana má nulovy tok. Algorithm pomocí funkce bfs(hledá cestu ze zdroju ke stoku pomocí algoritmu: prohledávání do šířky) nachází cestu.
 * Pak zvětšuje tok této cestý o increment(rozdíl mezí tokem a propustností hrany). To opakuje pokud bfs muže najít cestu.
 * 
 * @param source zdroj sítě
 * @param target stok sítě
 * @return int maximalní tok mezí zdrojem a stokem.
 */
int ford_fulkerson(int source, int target);

#endif