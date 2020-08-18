#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "utils.h"

char PARAM_FOLDER[] = "../params.txt";

void read_params(struct param_struct *params) {
    char line[1024];
    char name[1024];
    char value[1024];
    
    FILE *fp;
    
    fp = fopen(PARAM_FOLDER, "r");

    if(fp == NULL){
        printf("Can't open the file");
    }
    
    while (fgets(line, 1024, fp)) {
        if (strlen(line) && ('#' == line[0]))
            ; // comment in input, ignore
        else {
            sscanf(line, "%[ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghjiklmnopqrstuvwxyz]=%s\n", name, value);
        
            if (!strcmp(name, "SHARED_MEMORY_NAME"))
                strcpy(params->shared_memory_name, value);
            if (!strcmp(name, "SHM_SIZE"))
                params->size = atoi(value);
            if (!strcmp(name, "PERMISSIONS"))
                params->size = atoi(value);   
            name[0] = '\0';
            value[0] = '\0';
        }
    }
    printf("#### read params...\n");
    printf("shared memory name = %s\n", params->shared_memory_name);
    printf("size = %d\n", params->size);
    printf("permissions = %o\n", params->permissions);
    printf("### done!\n");
}