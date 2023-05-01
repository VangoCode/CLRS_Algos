GCC_FLAGS= -Wall -Werror -g -std=gnu99

heap : heap.o operations.o operations.h 
	gcc $(GCC_FLAGS) -o heap heap.o operations.o

heap.o : heap.c operations.h
	gcc $(GCC_FLAGS) -c heap.c operations.h

operations.o : operations.c operations.h
	gcc $(GCC_FLAGS) -c operations.c operations.h