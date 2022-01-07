#include "parameters.h"

/* Cesta vystupního souboru, na začatku je "undefined" */
char out_path[FILENAME_LEN] = UNDEFINED_PATH;
/* Cesta souboru s uzly, na začatku je "undefined" */                   
char node_path[FILENAME_LEN] = UNDEFINED_PATH;
/* Cesta souboru s hrany, na začatku je "undefined" */                
char edge_path[FILENAME_LEN] = UNDEFINED_PATH; 

int source_id = -1;
int target_id = -1;             
int is_valid = 0;                     
    
int format_check(char *name){
    char extension[EXTENSION_LEN];
    int name_len;
    
    if(!name){
        return 1;
    }
    
    /* Bereme 4 poslední symboly názvu a koukamé, aby se rovnali .csv*/
    name_len = strlen(name);
    strcpy(extension, &name[name_len - EXTENSION_LEN]);

    if(!strcmp(extension, CORRECT_EXTENSION)){
        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}

int parameters_processing(int argc, char *argv[]){
    int a;
    
    if(argc <= 1 || !argv){
        return EXIT_FAILURE_VERTEX;
    }

    /* Prochází všichní parametry a porovnáva s parametrý, ktere jsou v zadání*/
    for(a = 1; a < argc; ++a){
        if(strcmp(VERTEX_PARAMETER, argv[a]) == 0 && (a + 1 < argc)){
            if((!format_check(argv[a + 1])) && strcmp (UNDEFINED_PATH, node_path) == 0){
                strcpy(node_path, argv[a + 1]);
            }
        }
        
        else if(strcmp(EDGE_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            if((!format_check(argv[a + 1])) && strcmp (UNDEFINED_PATH, edge_path) == 0){
               strcpy(edge_path, argv[a + 1]);
            }
        }
        /*Pokud parameter out nebyl nalezen, necháva ho "undefined", pokud byl nalezén ale má špatný format
        vyplní řádek prazdním řádkem*/
        else if(strcmp(OUT_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            if(!format_check(argv[a + 1])){
                strcpy(out_path, argv[a + 1]);
            }
            else{
                strcpy(out_path, "");
            }
        }
        
        else if(strcmp(TARGET_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            target_id = atoi(argv[a + 1]);
        }
        
        else if(strcmp(SOURCE_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            source_id = atoi(argv[a + 1]);
        }
        /*Kontroluje valídnost sítě*/
        else if(strcmp(IS_VALID_PARAMETER, argv[a]) == 0){
            is_valid = 1;
        }
      }

    return EXIT_SUCCESS;
}