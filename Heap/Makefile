GCC_FLAGS= -Wall -Werror -g -std=gnu99

heap : heap.o operations.o operations.h 
	gcc $(GCC_FLAGS) -o heap heap.o operations.o ../DynamicArray/dynamic_table.o

heap.o : heap.c operations.h
	gcc $(GCC_FLAGS) -c heap.c operations.h ../DynamicArray/dynamic_table.h

operations.o : operations.c operations.h
	gcc $(GCC_FLAGS) -c operations.c operations.h