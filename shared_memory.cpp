#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#include "shared_memory.h"

#define IPC_RESULT_ERROR -1




static int get_shared_block(const char *filename, int size, int id) {
    key_t key;
    // printf("%s \n", FILENAME);
    key = ftok(filename,id);
    if (key == IPC_RESULT_ERROR) return IPC_RESULT_ERROR;

    return shmget(key,size,IPC_CREAT |0666);
}

my_object* attach_memory_block(const char *filename, int size, int id) {
    int shared_block_id = get_shared_block(filename,size,id);
    my_object* result;

    if (shared_block_id == IPC_RESULT_ERROR) perror("IPC_RESULT_ERROR: ");

    result = (my_object*)shmat(shared_block_id, NULL,0);
    if (result == (void *) IPC_RESULT_ERROR) perror("shmat: ");
    
    return result;
}

// const char * attach_memory_block(const char *filename, int size) {
//     int shared_block_id = get_shared_block(filename,size);
//     const char * result;

//     if (shared_block_id == IPC_RESULT_ERROR) return NULL;

//     result = shmat(shared_block_id, NULL,0);
//     if (result == (const char *) IPC_RESULT_ERROR) return NULL;
    
//     return result;
// }

bool detach_memory_block(my_object* block) {
    return (shmdt(block) != IPC_RESULT_ERROR);
}

bool free_memory_block(const char *filename,int id) {
    int shared_block_id = get_shared_block(filename,0,id);

    if (shared_block_id == IPC_RESULT_ERROR) return NULL;
    return (shmctl(shared_block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}

// int reader(void) {
//     my_object* block = attach_memory_block(FILENAME, BLOCK_SIZE);
    
    
//     printf("Reading: temp as %f and hum value as %f\n", block->temp,block->hum);
    
//     detach_memory_block(block);

    
//     if (free_memory_block(FILENAME)) {
//         printf("Free block: %s\n", FILENAME);
//     } else {
//         printf("Could not free block: %s\n",FILENAME);
//     }

//     return 0;
// }

// int writer(my_object* data_values) {
//     // printf("%s\n",FILENAME);
//     my_object* block = attach_memory_block(FILENAME, BLOCK_SIZE);
    
//     // float block = attach_memory_block(FILENAME,BLOCK_SIZE);
    
    
//     // strncpy((char *)block, "Hello World", BLOCK_SIZE);
//     block = data_values;

//     printf("Writing: temp as %f and hum value as %f\n", block->temp,block->hum);

    
//     detach_memory_block(block);

//     return 0;
    
// }