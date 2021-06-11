#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "shared_memory.h"


int main(int argc, char* argv[]) {
    my_object* status = attach_memory_block(FILENAME, BLOCK_SIZE, NUM_BLOCKS+1);
    // if (status->complete) {
    //     for (int i = 0; i <= NUM_BLOCKS; ++i) {
    //         if (free_memory_block(FILENAME,i)) {    
    //             printf("Free block: %d\n", i);
    //         } else {
    //             printf("Could not free block: %d\n",i);
    //         }
    //     }
    // } else {
    //     for (int i = 0; i <= status->cur_id; ++i) {
    //         if (free_memory_block(FILENAME,i)) {    
    //             printf("Free block: %d\n", i);
    //         } else {
    //             printf("Could not free block: %d\n",i);
    //         }
    //     }
    // }
    for (int i = 0; i <= NUM_BLOCKS; ++i) {
        if (free_memory_block(FILENAME,i)) {    
            printf("Free block: %d\n", i);
        } else {
            printf("Could not free block: %d\n",i);
        }
    }
    
    if (free_memory_block(FILENAME, NUM_BLOCKS+1)) {    
        printf("Free block: pointer\n");
    } else {
        printf("Could not free block: pointer\n");
    }
    
    

    return 0;
    
}