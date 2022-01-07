/**
 * @file loader.h
 * @author Pavel Shevnin
 * @brief Soubor který zabíva tím že načíta data z .csv souborů. 1. soubor je soubor s hranama grafu, 2. soubor s uzly
 * grafu. prochází teto dva souborý, a ukadá data do vector_t nodes. Každy uzel (node) obsahuje vector_t s hranama vycházejicí 
 * z tohoto uzlu. 
 * @version 1.3
 * @date 2021-12-20
 * 
 * 
 */
#ifndef _LOADER_H
#define _LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "vector.h"
#include "parameters.h"

/** @brief Používaný znak k oddělování hodnot v CSV souboru edges. */
#define EDGE_CSV_DELIMETER ",\""
/** @brief Používaný znak k oddělování hodnot v CSV souboru nodes. */
#define NODE_CSV_DELIMETER "," 
/** @brief Používaný znak k oddělování hodnot v CSV souboru nodes. */
#define WKT_CSV_DELIMETER "\"" 

/** @brief Správný format tabulky s hranama */
#define EDGE_TABLE_FORMAT "id,source,target,capacity,isvalid,WKT\n\0"
/** @brief Správný format tabulky s uzly */
#define NODE_TABLE_FORMAT "id,WKT\n\0"

/** @brief Návratova hodnota programu v připadě špatného formatu nazvu souboru s uzly */
#define EXIT_FAILURE_VERTEX 1
/** @brief Návratova hodnota programu v připadě špatného formatu nazvu souboru s hranama */
#define EXIT_FAILURE_EDGE 2
/** @brief Návratova hodnota programu v připadě když načtený index source neexistuje mezí uzlu */
#define EXIT_FAILURE_SOURCE 3
/** @brief Návratova hodnota programu v připadě když načtený index target neexistuje mezí uzlu */
#define EXIT_FAILURE_TARGET 4
/** @brief Návratova hodnota programu v připadě špatného formatu nazvu vystupního souboru */
#define EXIT_FAILURE_OUT 5
/** @brief Návratova hodnota programu v připadě když tok neexistuje */
#define EXIT_FAILURE_NO_FLOW 6
/** @brief Návratova hodnota programu v připadě jínych problemu */
#define EXIT_FAILURE_UNDEF 7

/** @brief Cesta do souboru s hodnotama neobsahuje nazev souboru*/
#define FILE_PATH "../data/\0"

/** @brief Velikost načítacího bufferu pro edge */
#define EDGE_CHAR_BUFFER_SIZE 8192
/** @brief Velikost načítacího bufferu pro node */
#define NODE_CHAR_BUFFER_SIZE 1024

/** @brief vector_t do kterého budou zapsáne indexy načtených uzlu a hran při načtení pro odstrnění dublicit */
extern vector_t *indexes;
/** @brief vector_t do kterého budou zapsáne všichní uzly grafu. Každy uzel obsahije hrany, které vvychází z tohoto uzlu. */
extern vector_t *nodes;

/**
 * @brief Funkce která přijíma id, prochází vector_t indexes a vrací 0 v případě, kdýž 
 * tento index načten ještě nebýl, vrací 1 kdýž tento index jíž existuje
 * 
 * @param id index který třeba zkontrolovat
 * @return int 0 až 1 v souvíslostí na vysledek kontroly
 */
int is_dublicate(int id);

/**
 * @brief Funkce přijímá ukazatel na cestu obsahujicí název souboru .csv pro uzly sítě.
 * Pak funkce prochází tento soubor, kontroluje že tabulka uzlů je ve správnem formatu, a načíta uzly do vectoru 
 * nodes. Při načtění take odstrňuje dublicity pomocí funkce is_dublicte 
 * 
 * @param path ukazatel na cestu ke souboru s uzly
 * @return int vrací 0 kdýž všchno je v pořadku
 */
int node_loader(char *path);

/**
 * @brief Funkce přijímá ukazatel na cestu obsahujicí název souboru .csv pro hrany sítě.
 * Pak funkce prochází tento soubor, kontroluje že tabulka hran je ve správnem formatu, a načíta hrany do vectoru 
 * edges pomocí funkce edge_to_node, ktera hledá spravný uzel pro tuto hranu. Při načtění take odstrňuje dublicity pomocí funkce is_dublicte
 * 
 * @param path ukazatel na cestu ke souboru .csv s uzly
 * @return int vrací 0 kdýž všchno je v pořadku
 */
int edge_loader(char *path, int is_valid);

/**
 * @brief Funkce slouží pro kontrolu jestli vector s uzly obsahuje index, který byl přidan uživatelém jako zdroj pro
 * vypočet maximalního toku. Pokud nebyl nalezen, vypíše chybovou hlášku
 * 
 * @param source index zdroju
 * @return int vrací 0 pokud mezí načtené uzly je nalezen zdroj. Vrací 3 pokud zdroj nalezen nebyl
 */
int source_in_graph(int source);

/**
 * @brief Funkce slouží pro kontrolu jestli vector s uzly obsahuje index, který byl přidan uživatelém jako stok pro
 * vypočet maximalního toku
 * 
 * @param source index stoku
 * @return int int vrací 0 pokud mezí načtené uzly je nalezen zdroj. Vrací 4 pokud zdroj nalezen nebyl
 */
int target_in_graph(int target);

#endif