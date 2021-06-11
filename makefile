CC=gcc
CFLAGS=-lwiringPi
DEPS = shared_memory.h

all: write read free

write: writeshmem.o shared_memory.o simpleDHT11func.o 
	$(CC) -o write writeshmem.o shared_memory.o simpleDHT11func.o $(CFLAGS)

read: readshmem.o shared_memory.o
	$(CC) -o read readshmem.o shared_memory.o $(CFLAGS)

free: freeshmem.o shared_memory.o
	$(CC) -o free freeshmem.o shared_memory.o $(CFLAGS)

dht: simpleDHT11main.o simpleDHT11func.o 
	$(CC) -o simple simpleDHT11main.o simpleDHT11func.o $(CFLAGS)

time: time.o
	$(CC) -o time time.o

clean:
	rm *.o read write free simple 