#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parameters.h"

char out_path[FILENAME_LEN] = "../data/out.csv\0";                   
char node_path[FILENAME_LEN] = "undefined\0";                
char edge_path[FILENAME_LEN] = "undefined\0"; 
int source_id = -1;
int target_id = -1;             
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
 * @brief Prijima parametry z prikazove radky, a rozdeluje je do 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int parameters_procesing(int argc, char *argv[]){
    int i;
    if(argc <= 1 || !argv){
        printf("Parameters error. \n");
        return 7;
    }

    for(i = 1; i < argc; ++i){
        if(strcmp (VERTEX_PARAMETER, argv[i]) == 0 && (i + 1 < argc)){
            
            if((!format_check(argv[i + 1])) && strcmp (UNDEFINED_PATH, node_path) == 0){
                strcpy(node_path, DIRECTORY_PATH);
                strcat(node_path, argv[i + 1]);
            }

        }
        else if(strcmp (EDGE_PARAMETER, argv[i]) == 0 && (i + 1 <= argc)){ 
            if((!format_check(argv[i + 1])) && strcmp (UNDEFINED_PATH, edge_path) == 0){
                strcpy(edge_path, DIRECTORY_PATH);
                strcat(edge_path, argv[i + 1]);
            }
        }
        else if(strcmp (OUT_PARAMETER, argv[i]) == 0 && (i + 1 <= argc)){ 
            if(!format_check(argv[i + 1])){
                strcpy(out_path, DIRECTORY_PATH);
                strcat(out_path, argv[i + 1]);
            }
        }
        else if(strcmp (TARGET_PARAMETER, argv[i]) == 0 && (i + 1 <= argc)){ 
            target_id = atoi(argv[i + 1]);
        }
        else if(strcmp (SOURCE_PARAMETER, argv[i]) == 0 && (i + 1 <= argc)){ 
            source_id = atoi(argv[i + 1]);
            
        }
        else if (strcmp (IS_VALID_PARAMETER, argv[i]) == 0){
            is_valid = 1;
        }
      
    }
}