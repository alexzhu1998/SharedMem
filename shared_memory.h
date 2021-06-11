#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdbool.h>
#include <string>

struct my_object {
    // char * datetime;
    float temp;
    float hum;
};


// attach a shared memory block, associated with filename, create if doesnt exist

my_object* attach_memory_block(const char *filename, int size,int id);
// float attach_memory_block(char *filename, int size);
bool detach_memory_block(my_object* block);
// bool detach_memory_block(float block);
bool free_memory_block(const char *filename,int id);

// all of the programs will share these values
#define BLOCK_SIZE 100
#define NUM_BLOCKS 100
#define FILENAME "writeshmem.cpp"

#endif
