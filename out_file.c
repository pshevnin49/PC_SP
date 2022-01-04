#include "out_file.h"

FILE *out_file;

int out_write(char *name){
    size_t a;
    edge_t *out_edge;
    
    if(!name){
        printf("Invalid output file.\n");
        return EXIT_FAILURE_OUT;
    }

    out_file = fopen(name, WRITE);
    if(!out_file){
        printf("Invalid output file.\n");
        return EXIT_FAILURE_OUT;
    }

    if(!out_edges){
        return EXIT_FAILURE_UNDEF;
        fclose(out_file);
    }

    fprintf(out_file, "%s\n", EDGE_TABLE_FORMAT);

    for(a = 0; a < out_edges->count; ++a){
        out_edge = *(edge_t **)vector_at(out_edges, a);
        
        if(!out_edge){
            return EXIT_FAILURE_UNDEF;
        }

        if(out_edge->is_valid){
            fprintf(out_file, "%d, %d, %d, %d, %s, \"%s\"\n", out_edge->id, out_edge->source, out_edge->target, out_edge->capacity, "True", out_edge->wkt);
        }
        else{
            fprintf(out_file, "%d, %d, %d, %d, %s, \"%s\"\n", out_edge->id, out_edge->source, out_edge->target, out_edge->capacity, "False", out_edge->wkt);
        }
    }

    fclose(out_file);
    return EXIT_SUCCESS;
}


