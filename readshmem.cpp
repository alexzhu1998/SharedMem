#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "shared_memory.h"


int main(int argc, char* argv[]) {

    my_object* status = attach_memory_block(FILENAME,BLOCK_SIZE,NUM_BLOCKS+1);
    my_object* block;
    block = attach_memory_block(FILENAME, BLOCK_SIZE,status->cur_id);
    printf("Reading %d: %s temp as %.2f and hum value as %.2f\n", status->cur_id,block->datetime, block->temp,block->hum);
    detach_memory_block(block);
    detach_memory_block(status);
    return 0;
    
}