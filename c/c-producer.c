#include <stdio.h> 
#include <errno.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "utils.h"


int main() { 
    char data[] = "this_is_my_data_to_write";
    int fd;
    void *pSharedMemory = NULL;
    struct param_struct params;
    printf("1");

    read_params(&params);
printf("2");
    // get a handle to the shared memory
    fd = shm_open(params.shared_memory_name, O_RDWR, params.permissions);
        
    if (fd == -1) {
        printf("Couldn't get a handle to the shared memory; errno is %d", errno);
        return 0; 
    }


    // mmap it.
    pSharedMemory = mmap((void *)0, (size_t)params.size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (pSharedMemory == MAP_FAILED) {
        printf("MMapping the shared memory failed; errno is %d", errno);
        return 0; 
    }

    strcpy((char *)pSharedMemory, data);     
  
    return 0; 
}