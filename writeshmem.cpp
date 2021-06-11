#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <time.h> //for time


#include "shared_memory.h"
#include "simpleDHT11.h"


void assign_time(char* datetime) {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(datetime,asctime (timeinfo));
}

int main(int argc, char* argv[]) {
    // printf("%s\n",FILENAME);
    DHT dht;
    int chk;


    printf("Program is starting ... \n");
    my_object* status = attach_memory_block(FILENAME, BLOCK_SIZE, NUM_BLOCKS+1);
    my_object* block;
    int i = 0;
    while (true) {
        if (i == NUM_BLOCKS) {
            i = 0;
            status->complete = true;
        }
        chk = dht.readDHT11(DHT11_Pin);
        if (chk == DHTLIB_OK) {
            printf("DHT11, OK! \n");
        } else {
            printf("DHT11, Not OK! chk: %d\n", chk);
            return -1;
        }
        block = attach_memory_block(FILENAME,BLOCK_SIZE,i);
        assign_time(block->datetime);
        block->temp = dht.temperature;
        block->hum = dht.humidity;
        printf("Writing: temp as %.2f and hum value as %.2f\n", block->temp,block->hum);
        detach_memory_block(block);

        status->cur_id = i;
        ++i;
    }
    
    // strncpy((char *)block, "Hello World", BLOCK_SIZE);

    detach_memory_block(status);
    printf("End Writing\n");
    

    return 0;
    
}