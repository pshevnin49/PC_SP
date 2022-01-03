#include "node.h"
#include "edge.h"
#include "vector.h"

node_t *node_create(const int id, const char *wkt){

    node_t *new;
    if (!wkt || strlen(wkt) == 0) {
        return NULL;
    }

    new = (node_t *)malloc(sizeof(node_t));
    if(!new){
        return NULL;
    }

    new->id = id;
    new->color = 0;
    new->pred = -1;

    new->wkt = (char *)malloc(strlen(wkt) + 1);
    if (!new->wkt) {
        free(new);
        return NULL;
    }
    strcpy(new->wkt, wkt);
    
    new->edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);// this is new
   
    return new;

}

/**
 * @brief Funkce pro uvolnění osoby.
 * @param poor Uvolňována osoba.
 */
void node_destroy(node_t **poor){
    if (!poor || !*poor) {
        return;
    }

    (*poor)->id = 0;
    (*poor)->pred = 0;
    (*poor)->color = 0;
    free((*poor)->wkt);    
    (*poor)->wkt = NULL;
    vector_destroy(&((*poor)->edges));

    free(*poor); /* Tady zkusíme udělat změnu a podíváme se, jak se bude valgrind chovat! */
    *poor = NULL;
}

/**
 * @brief Funkce vytiskne osobu do konzole.
 * @param p Tištěná osoba.
 */
void node_print(const node_t *node){
    int i;

    if (!node) {
        printf("ERROR empty pointer");
        return;
    }
    
    printf("(%d: %s)\n", node->id, node->wkt);
    printf("Edges{\n");
    for(i = 0; i < node->edges->count; ++i){//thid is new too
         edge_print(*(edge_t **)vector_at(node->edges, i)); 
    }
    printf("}\n");
}