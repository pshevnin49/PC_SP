/**
 * @file out_file.h
 * @author Pavel Shevnin
 * @brief Zabýva tím, že vypisuje hrany minimálního řezu z vectoru do souboru out.csv.
 * Před vypísem hrany jsou seřazeny podle indexu
 * @version 1.0
 * @date 2021-12-25
 * 
 */
#ifndef _OUT_FILE_H
#define _OUT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "vector.h"
#include "loader.h"
#include "algorithm.h"
#include "parameters.h"

/** @brief Definice pro vypis pri vytvaření nového FILE */
#define WRITE "w"

/**
 * @brief Funkce out_write přijíma jako parameter jméno souboru ve formatu .csv. Pak, v případě když jmeno není nulove a neni "undefined" generuje soubor
 * a do tohoto souboru zapisuje hlavičku pro hrany (id,source,target,capacity,isvalid,WKT) a všichní hrany minimalního řezu seřazené podle id. 
 * 
 * @param name jmeno vystupního .csv souboru.
 * @return int vrácí 0 v případě uspěšné generace out souboru, vrací 5 pokud dojde k chybě při generace 
 * souboru, nebo když jmeno souboru bude prázdné
 */
int out_write(char *name);

#endif