#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared_memory.h"
#include "simpleDHT11.h"

int main(int argc, char* argv[]) {
    // printf("%s\n",FILENAME);
    DHT dht;
    int chk;

    printf("Program is starting ... \n");
    chk = dht.readDHT11Once(DHT11_Pin);
    if (chk == DHTLIB_OK) {
        printf("DHT11, OK! \n");
    } else {
        printf("DHT11, Not OK! chk: %d\n", chk);
        return -1;
    }

    my_object* block = attach_memory_block(FILENAME,BLOCK_SIZE,0);
    
    
    // strncpy((char *)block, "Hello World", BLOCK_SIZE);
    block->temp = dht.temperature;
    block->hum = dht.humidity;

    printf("Writing: temp as %2f and hum value as %2f\n", block->temp,block->hum);

    
    detach_memory_block(block);

    return 0;
    
}