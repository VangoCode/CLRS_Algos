GCC_FLAGS= -Wall -Werror -g -std=gnu99

all : main
	+$(MAKE) -C DynamicArray
	+$(MAKE) -C Heap
	+$(MAKE) -C PriorityQueue

main : main.o
	gcc $(GCC_FLAGS) -o main main.o -lSDL2 -lSDL2main

main.o: main.c
	gcc $(GCC_FLAGS) -c main.c -lSDL2 -lSDL2mains

clean:
	+$(MAKE) -C DynamicArray clean
	+$(MAKE) -C Heap clean
	+$(MAKE) -C PriorityQueue clean