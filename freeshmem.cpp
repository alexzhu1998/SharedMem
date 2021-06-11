#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "shared_memory.h"


int main(int argc, char* argv[]) {
    
    for (int i = 0; i < NUM_BLOCKS; ++i) {
        if (free_memory_block(FILENAME,i)) {    
            printf("Free block: %d\n", i);
        } else {
            printf("Could not free block: %s\n",FILENAME);
        }
    }
    

    return 0;
    
}