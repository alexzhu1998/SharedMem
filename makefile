CC=gcc
CFLAGS=-lwiringPi
DEPS = simpleDHT11.h

all: write read

write: writeshmem.o shared_memory.o simpleDHT11func.o 
	$(CC) -o write writeshmem.o shared_memory.o simpleDHT11func.o $(CFLAGS)

read: readshmem.o shared_memory.o
	$(CC) -o read readshmem.o shared_memory.o $(CFLAGS)

dht: simpleDHT11main.o simpleDHT11func.o 
	$(CC) -o simple simpleDHT11main.o simpleDHT11func.o $(CFLAGS)

clean:
	rm *.o simple read