#include "edge.h"

/**
 * @brief Funkce která tvoří novou hranu. Přijíma parametrý:
 * 
 * @param id index nové hrany
 * @param source index bodu ze kterého hrana vychazí
 * @param target index bodu kterým hrana končí
 * @param capacity propustnost hrany
 * @param is_valid jakou validnost tato hrana má "True" nebo "False"
 * @param wkt Souřadníce kterýma tato hrana prochází
 * @return edge_t* ukazatel na hranu
 */
edge_t *edge_create(const int id, const int source, const int target, const int capacity, const int is_valid, const char *wkt){
    edge_t *new;
    
    if (!wkt || strlen(wkt) == 0) {
        return NULL;
    }

    new = (edge_t *)malloc(sizeof(edge_t));
    if(!new){
        return NULL;
    }

    new->wkt = (char *)malloc(strlen(wkt) + 1);
    if (!new->wkt) {
        free(new);
        return NULL;
    }
   
    strcpy(new->wkt, wkt);
    new->id = id;
    new->source = source;
    new->target = target;
    new->capacity = capacity;
    new->is_valid = is_valid;
    new->flow = 0;

    return new;
}

/**
 * @brief Funkce uvolňuje paměť struktury "Edge"
 * 
 * @param poor 
 */
void edge_destroy(edge_t **poor) {
    
    if (!poor || !*poor) {
        return;
    }
    
    (*poor)->id = 0;
    (*poor)->source = 0;
    (*poor)->target = 0;
    (*poor)->capacity = 0;
    (*poor)->is_valid = 0;
    (*poor)->flow = 0;
    free((*poor)->wkt);    
    (*poor)->wkt = NULL;
    free(*poor); 
    *poor = NULL;
}


void edge_print(const edge_t *edge) {

    if (!edge) {
        printf("ERROR empty pointer");
        return;
    }

    printf("(%d: %d, %d, %d, %d, %s)\n", edge->id, edge->source, edge->target, edge->capacity, edge->is_valid, edge->wkt);
}
