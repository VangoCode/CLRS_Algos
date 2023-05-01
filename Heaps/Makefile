GCC_FLAGS= -Wall -Werror -g -std=gnu99

heaps : heaps.o operations.o operations.h 
	gcc $(GCC_FLAGS) -o heaps heaps.o operations.o

heaps.o : heaps.c operations.h
	gcc $(GCC_FLAGS) -c heaps.c operations.h

operations.o : operations.c operations.h
	gcc $(GCC_FLAGS) -c operations.c operations.h