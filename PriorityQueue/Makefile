GCC_FLAGS= -Wall -Werror -g -std=gnu99

priority_queue : priority_queue.o operations.o operations.h 
	gcc $(GCC_FLAGS) -o priority_queue priority_queue.o operations.o ../DynamicArray/dynamic_table.o ../Heap/operations.o

priority_queue.o : priority_queue.c operations.h
	gcc $(GCC_FLAGS) -c priority_queue.c operations.h ../DynamicArray/dynamic_table.h ../Heap/operations.h

operations.o : operations.c operations.h
	gcc $(GCC_FLAGS) -c operations.c operations.h