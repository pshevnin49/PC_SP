/**
 * @file main.c
 * @author Pavel Shevnin
 * @brief Hlavní řidicí soubor programu, zabivajicího vypočtém maximalního toku v neotientovaném ohodnoceném grafu, který reprezentuje dopravní síť
 * @version 1.4
 * @date 2021-12-07
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parameters.h"
#include "loader.h"
#include "algorithm.h"
#include "out_file.h"

/**
 * @brief Hlávní řidicí funkce celého programu. Tato funkce volá všicní funkce programu, a kontroluje aby jako výstup mněli 0
 * Když nějaka funkce má odlíšny od 0 vystup, volá clean_and_exit(), ktery slouží k vyčištění pamětí a vracení exitu. V připadě uspěšneho ukončení 
 * prográmu funkce main vypíše do konzole Max network flow is |x| = <n> kde n je maximalní tok sítě, a vrátí hodnotu 0.
 * 
 * @param argc pocet parametrů z přikazové řadky
 * @param argv pole parametrů z přikazové řadky
 * @return int 0 když všecchno je v pořadku; 1 když chybí soubor uzlů; 2 když chybí soubor hran; 3 když chybí source;
 * 4 když chybí target
 */
int main(int argc, char *argv[]) {
    int exit, max_flow;

    exit = 0;

    #define clean_and_exit();        \
        vector_destroy(&nodes);      \
        return exit;

    parameters_processing(argc, argv);

    exit = node_loader(node_path);
    if(exit){
        clean_and_exit();
    }
    
    exit = edge_loader(edge_path, is_valid);
    if(exit){
        clean_and_exit();
    }
    
    exit = source_in_graph(source_id);
    if(exit){
        clean_and_exit();
    }
    
    exit = target_in_graph(target_id);
    if(exit){
        clean_and_exit();
    }
    
    max_flow = ford_fulkerson(source_id, target_id);
    if(!max_flow){
        printf("Max network flow is |x| = %d", max_flow);
        vector_destroy(&nodes);
        return EXIT_FAILURE_NO_FLOW;
    }
    
    exit = out_write(out_path);
    if(exit){
       clean_and_exit();
    }
    
    printf("Max network flow is |x| = %d", max_flow);

    #undef clean_and_exit
    vector_destroy(&nodes);
    return exit;
}