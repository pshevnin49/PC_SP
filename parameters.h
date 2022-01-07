/**
 * @file parameters.h
 * @author Pavel Shevnin
 * @brief soubor parameters.h obsahuje funkce parameters_processing a format_check, a zabýva tím, že přijíma, kontroluje a zpracováva 
 * parametrý z příkazové řadky pří spuštění programu.
 * @version 1.2
 * @date 2021-12-20
 * 
 */

#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loader.h"
/** @brief format vlajky označujicí soubor uzlů*/
#define VERTEX_PARAMETER "-v\0"
/** @brief format vlajky označujicí soubor hran*/
#define EDGE_PARAMETER "-e\0"
/** @brief format vlajky označujicí index zdroje*/
#define SOURCE_PARAMETER "-s\0"
/** @brief format vlajky označujicí index stoku*/
#define TARGET_PARAMETER "-t\0"
/** @brief format vlajky označujicí vystupní soubor*/
#define OUT_PARAMETER "-out\0"
/** @brief format vlajky označujicí is_valid parameter*/
#define IS_VALID_PARAMETER "-a\0"

/** @brief délka formátu souboru (.csv)*/
#define EXTENSION_LEN 4
/** @brief správný format CSV souboru*/
#define CORRECT_EXTENSION ".csv\0"
/** @brief nedefinovaná cesta*/
#define UNDEFINED_PATH "undefined\0"
/** @brief maximalní počet symbolů jmena souboru*/
#define FILENAME_LEN 256

/** @brief cesta do vystupního souboru*/
extern char out_path[];
/** @brief cesta do souboru s uzly sítě*/
extern char node_path[];
/** @brief cesta do souboru s hrany sítě*/                
extern char edge_path[]; 
/** @brief čislo označujicí index zdroje*/
extern int source_id;
/** @brief čislo označujicí index stoku*/
extern int target_id;   
/** @brief parameter označujicí validnost sítě (budou využitý jen True hrány, nebo všichní)*/          
extern int is_valid; 

/**
 * @brief Funkce přijíma jako parameter jméno souboru, a kontroluje aby tento soubor měl správný format (.csv) v připadě když format je správný, vrací 0 (EXIT_SUCCESS)
 * v opačném připadě vraci 1 (EXIT_FAILURE)
 * 
 * @param name 
 * @return int 
 */
int format_check(char *name);

/**
 * @brief Funkce parameters_processing přjíma z přikazové řadky pole parametrů a jejích počet. Pak procházi celé pole a kontroluje jestlí parameter není jdním z požadovaných. 
 * Kdýž je to tak, zapisuje parameter do správné proměnné. V připadě kdýž parameter je jménem jedného ze souborů, před zapsáním do proměnné, kontroluje aby to jmeno mělo správný format, 
 * když má správný format, připojuje k tomu jménu cestu ke souboru (data/) a ukladá do správne proměnné.
 * 
 * @param argc počet parametrů
 * @param argv pole parametrů
 * @return int 
 */
int parameters_processing(int argc, char *argv[]);

#endif
