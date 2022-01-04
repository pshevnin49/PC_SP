#include "edge.h"


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

