#include "node.h"

node_t *node_create(const int id, const char *wkt){
    node_t *new;
    
    if (!wkt || strlen(wkt) == 0){
        return NULL;
    }

    new = (node_t *)malloc(sizeof(node_t));
    if(!new){
        return NULL;
    }
    
    new->id = id;
    new->pred = -1;
    new->color = 0;
    new->wkt = (char *)malloc(strlen(wkt) + 1);

    if(!new->wkt){
        free(new);
        return NULL;
    }
    
    strcpy(new->wkt, wkt);
    new->edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);
   
    return new;

}

void node_destroy(node_t **poor){
    
    if(!poor || !*poor){
        return;
    }

    (*poor)->id = 0;
    (*poor)->pred = 0;
    (*poor)->color = 0;
    free((*poor)->wkt);    
    (*poor)->wkt = NULL;
    vector_destroy(&((*poor)->edges));

    free(*poor); 
    *poor = NULL;
}
