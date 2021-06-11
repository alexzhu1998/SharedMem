#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "shared_memory.h"


int main(int argc, char* argv[]) {
    my_object* block = attach_memory_block(FILENAME, BLOCK_SIZE,0);
    
    
    printf("Reading: temp as %2f and hum value as %2f\n", block->temp,block->hum);
    
    detach_memory_block(block);


    return 0;
    
}