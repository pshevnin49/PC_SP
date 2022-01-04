#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parameters.h"
#include "loader.h"
#include "ford_fulkerson.h"
#include "out_file.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
    int exit, max_flow;
    
    parameters_processing(argc, argv);
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

    max_flow = ford_fulkerson(source_id, target_id);
    if(!max_flow){
        return EXIT_FAILURE_NO_FLOW;
    }

    exit = out_write(out_path);
    if(exit){
        return exit;
    }
    
    printf("Max network flow is |x| = %d", max_flow);

    vector_destroy(&nodes);
    return exit;
}