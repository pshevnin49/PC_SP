#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parameters.h"
#include "loader.h"
#include "ford_fulkerson.h"



int main(int argc, char *argv[]) {
    int exit;
    
    parameters_procesing(argc, argv);
    printf("argument vertex %s\n", node_path);
    printf("argument edge %s\n", edge_path);
    printf("source %d\n", source_id);
    printf("target %d\n", target_id);
    printf("is valid %d\n", is_valid);

    exit = 0;
    exit = node_loader(node_path);
    if(exit){
        return exit;
    }
    
    exit = edge_loader(edge_path, is_valid);
    if(exit){
        return exit;
    }

    exit = source_in_graph(source_id);
    if(exit){
        return exit;
    }

    exit = target_in_graph(target_id);
    if(exit){
        return exit;
    }
    
    printf("Max flow: %d", ford_fulkerson(source_id, target_id));

    return EXIT_SUCCESS;
}