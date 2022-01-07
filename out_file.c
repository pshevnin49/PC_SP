#include "out_file.h"

/* vystupní soubor */
FILE *out_file;

/**
 * @brief Comparator slouží ke seřazení hran minimalního řezu, které jsou připravene k vypisu do .csv souboru. 
 * Přijímá ukazatelé na dvě hrany, porovnáva indexy těcto hran, a vrací kladné nebo zaporné číslo
 * @param edge1 první porovnávaná hrana 
 * @param edge2 druha porovnávaná hrana 
 * @return int vystup je kladný, kdýž index první hrany je větší, záporný, kdýž větší je index druhé hrany. nula když jsou stejná
 */
int comparator(const void *edge1, const void *edge2){
    return ((*(edge_t **)edge1)->id - (*(edge_t **)edge2)->id);              
}

int out_write(char *name){
    size_t a;
    edge_t *out_edge;
    
    if(!name){
        printf("Invalid output file.\n");
        return EXIT_FAILURE_OUT;
    }

    /*Pokud jmeno souboru out nebylo definovano vrací 0, a program běží dál*/
    if(!strcmp(name, UNDEFINED_PATH)){
        return EXIT_SUCCESS;
    }

    if(!out_edges){
        fclose(out_file);
        return EXIT_FAILURE_UNDEF;
    }

    out_file = fopen(name, WRITE);
    if(!out_file){
        printf("Invalid output file.\n");
        return EXIT_FAILURE_OUT;
    }

    fprintf(out_file, "%s", EDGE_TABLE_FORMAT);
    
    /* Seřázení hran pomocí funkce qsort z knihovny stdlib.h */
    qsort(out_edges->data, out_edges->count, sizeof(edge_t*), comparator);

    for(a = 0; a < out_edges->count; ++a){
        out_edge = *(edge_t **)vector_at(out_edges, a);
        
        if(!out_edge){
            return EXIT_FAILURE_UNDEF;
        }
        /*Pokud hrana je validní vrací čáru True pokud ne - False */
        if(out_edge->is_valid){
            fprintf(out_file, "%d,%d,%d,%d,%s,\"%s\"\n", out_edge->id, out_edge->source, out_edge->target, out_edge->capacity, "True", out_edge->wkt);
        }
        else{
            fprintf(out_file, "%d,%d,%d,%d,%s\"%s\"\n", out_edge->id, out_edge->source, out_edge->target, out_edge->capacity, "False", out_edge->wkt);
        }
    }

    fclose(out_file);
    return EXIT_SUCCESS;
}




