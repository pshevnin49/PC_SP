#include "parameters.h"


char out_path[FILENAME_LEN] = "data/out.csv\0";                   
char node_path[FILENAME_LEN] = UNDEFINED_PATH;                
char edge_path[FILENAME_LEN] = UNDEFINED_PATH; 
int source_id = 0;
int target_id = 0;             
int is_valid = 0;                     
    
/**
 * @brief vraci 0, kdyz format nazvu je dobry 
 * 
 * @param name 
 * @return int 
 */
int format_check(char *name){
    char extension[EXTENSION_LEN];
    int name_len;
    
    if(!name){
        return 1;
    }

    name_len = strlen(name);
    strcpy(extension, &name[name_len - EXTENSION_LEN]);

    if(strcmp(extension, CORRECT_EXTENSION)){
        return 1;
    }
    
    return 0;
}

/**
 * @brief Prijima parametry z prikazove radky, a rozdeluje je do spravnych promennych
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int parameters_processing(int argc, char *argv[]){
    int a;
    
    if(argc <= 1 || !argv){
        printf("Parameters error. \n");
        return EXIT_FAILURE_UNDEF;
    }

    for(a = 1; a < argc; ++a){
        if(strcmp (VERTEX_PARAMETER, argv[a]) == 0 && (a + 1 < argc)){
            if((!format_check(argv[a + 1])) && strcmp (UNDEFINED_PATH, node_path) == 0){
                printf("Vertex\n");
                strcpy(node_path, DIRECTORY_PATH);
                strcat(node_path, argv[a + 1]);
            }
        }
        
        else if(strcmp (EDGE_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            if((!format_check(argv[a + 1])) && strcmp (UNDEFINED_PATH, edge_path) == 0){
                strcpy(edge_path, DIRECTORY_PATH);
                strcat(edge_path, argv[a + 1]);
            }
        }
        
        else if(strcmp (OUT_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            if(!format_check(argv[a + 1])){
                strcpy(out_path, DIRECTORY_PATH);
                strcat(out_path, argv[a + 1]);
            }
            else{
                strcat(out_path, "");
            }
        }
        
        else if(strcmp (TARGET_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            target_id = atoi(argv[a + 1]);
        }
        
        else if(strcmp (SOURCE_PARAMETER, argv[a]) == 0 && (a + 1 <= argc)){ 
            source_id = atoi(argv[a + 1]);
        }
        
        else if(strcmp (IS_VALID_PARAMETER, argv[a]) == 0){
            is_valid = 1;
        }
      }

    return EXIT_SUCCESS;
}