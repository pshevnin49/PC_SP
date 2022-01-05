
#include "loader.h"

vector_t *indexes;
vector_t *nodes;

int edge_format_check(char *edge_format){
    if(!edge_format){
        return 1;
    }
    return !strcmp(EDGE_TABLE_FORMAT, edge_format);
}

int node_format_check(char *node_format){
    if(!node_format){
        return 1;
    }
    return !strcmp(NODE_TABLE_FORMAT, node_format);
}

int edge_to_node(edge_t *edge){
    int a;
    int source; 
    node_t *node_new;
    
    if(!edge){
        return 1;
    }
    
    if(!nodes){
        return 1;
    }
    
    source = edge->source;
   
    for(a = 0; nodes->count; ++a){
        node_new = *(node_t **)vector_at(nodes, a);
        if(node_new->id == source){
            vector_push_back(node_new->edges, &edge);
            return 0;
        } 
    }
    return 1;
}

int is_dublicate(int id){
    size_t a;

    if(!indexes){
        return 0;
    }
    if(indexes){
        for(a = 0; a < vector_count(indexes); ++a){
            if(id == *(int *)vector_at(indexes, a)){
                return 1;
            }
        }
    }
    return 0;
}

int node_loader(char *path) {
    char line[NODE_CHAR_BUFFER_SIZE] = { 0 }, *wkt;
    int node_id; 
    char *symbols_arr;
    FILE *file = NULL;
    node_t *node;
    
    #define clean_and_exit()        \
        vector_destroy(&indexes);   \
        vector_destroy(&nodes);     \
        fclose(file);               \
        return EXIT_FAILURE_VERTEX;               
        
    if(!path){
        printf("Invalid vertex file.\n");
        clean_and_exit();
    }

    file = fopen(path, "r");
    if (!file) {
        printf("Invalid vertex file.\n");
        clean_and_exit();
    }
    
    indexes = vector_create(sizeof(int), NULL);
    if (!indexes) {
        printf("Indexes vector create ERROR.\n");
        clean_and_exit();
    }
    
    nodes = vector_create(sizeof(node_t *), (vec_it_dealloc_t)node_destroy);
    if (!nodes) {
        printf("Nodes vector create ERROR.\n");
        clean_and_exit();
    }
    
    fgets(line, NODE_CHAR_BUFFER_SIZE, file);
    if(node_format_check(line)){
        printf("Invalid vertex file.\n");
        clean_and_exit();
    }
   
    while (fgets(line, NODE_CHAR_BUFFER_SIZE, file)) {
        if (strlen(line) <= 1) {
            continue;
        }
        symbols_arr = strtok(line, NODE_CSV_DELIMETER);
        node_id = atoi(symbols_arr);
        
        if(is_dublicate(node_id)){
            continue;
        }

        wkt = strtok(NULL, NODE_CSV_DELIMETER);

        node = node_create(node_id, wkt);
        if(!node){ 
            printf("Node structure create ERROR.\n");
            clean_and_exit();
        }
        
        vector_push_back(nodes, &node);
        vector_push_back(indexes, &node_id);
    }
    
    vector_destroy(&indexes);
    fclose(file);
    #undef clean_and_exit
    return EXIT_SUCCESS;
}

int edge_loader(char *path, int is_valid) {
    char line[EDGE_CHAR_BUFFER_SIZE] = { 0 }, *wkt;
    int edge_id, edge_src, edge_target, edge_capacity, edge_valid;
    char *symbols_arr;
    FILE *file = NULL;
    vector_t *edges;
    edge_t *edge;

    #define clean_and_exit()        \
        vector_destroy(&indexes);   \
        vector_destroy(&edges);     \
        fclose(file);               \
        return EXIT_FAILURE_EDGE;

    if(!path){
        printf("Invalid edge file.\n");
        clean_and_exit();
    }
    
    file = fopen(path, "r");
    if (!file) {
        printf("Invalid edge file.\n");
        clean_and_exit();
    }
    
    indexes = vector_create(sizeof(int), NULL);
    if (!indexes) {
        printf("Indexes vector create ERROR.\n");
        clean_and_exit();
    }

    edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);
    if(!edges) {
        printf("Edges vector create ERROR.\n");
        clean_and_exit();
    }

    fgets(line, EDGE_CHAR_BUFFER_SIZE, file);

    /*Kontorola formatu vstupni tabulky*/
    if(edge_format_check(line)){
        printf("Invalid edge file.\n");
        clean_and_exit();
    }

    while(fgets(line, EDGE_CHAR_BUFFER_SIZE, file)) {
        
        if(strlen(line) <= 1) {
            continue;
        }

        symbols_arr = strtok(line, EDGE_CSV_DELIMETER);
        edge_id = atoi(symbols_arr);
        
        if(is_dublicate(edge_id)){
            continue;
        }

        symbols_arr = strtok (NULL, EDGE_CSV_DELIMETER);
        edge_src = atoi(symbols_arr);
        
        symbols_arr = strtok(NULL, EDGE_CSV_DELIMETER);
        edge_target = atoi(symbols_arr);
        
        symbols_arr = strtok(NULL, EDGE_CSV_DELIMETER);
        edge_capacity = atoi(symbols_arr);      
        
        symbols_arr = strtok(NULL, EDGE_CSV_DELIMETER);

        if(!strcmp("True", symbols_arr)){ 
            edge_valid = 1;
        }
        else{
            if(!is_valid){
                continue;
            }
            else{
                edge_valid = 0;
            }
        }
        
        wkt = strtok(NULL, EDGE_CSV_DELIMETER);
        wkt[strcspn(wkt, "\r\n")] = 0;
        edge = edge_create(edge_id, edge_src, edge_target, edge_capacity, edge_valid, wkt);

        if(!edge){
            printf("Edge structure create ERROR.\n");
            clean_and_exit();
        }
        
        edge_to_node(edge);
        vector_push_back(indexes, &edge_id);
    }

    vector_destroy(&indexes);
    #undef clean_and_exit
    return EXIT_SUCCESS;
}

int source_in_graph(int source){
    size_t a;
    
    for(a = 0; a < nodes->count; ++a){
        if((*(node_t **)vector_at(nodes, a))->id == source){
            return 0;
        }
    }
    printf("Invalid source vertex.\n");
    return EXIT_FAILURE_SOURCE;
}

int target_in_graph(int target){
    size_t a;
    
    for(a = 0; a < nodes->count; ++a){
        if((*(node_t **)vector_at(nodes, a))->id == target){
            return 0;
        }
    }

    printf("Invalid sink vertex.\n");
    return EXIT_FAILURE_TARGET;

}





