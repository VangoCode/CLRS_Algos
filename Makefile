GCC_FLAGS= -Wall -Werror -g -std=gnu99
HEAP_PATH=./heaps/

all : heaps

heaps : heaps.o operations.o operations.h 
	gcc $(GCC_FLAGS) -o $(HEAP_PATH)heaps heaps.o $(HEAP_PATH)operations.o

heaps.o : heaps.c operations.h
	gcc $(GCC_FLAGS) -c $(HEAP_PATH)heaps.c $(HEAP_PATH)operations.h

operations.o : operations.c operations.h
	gcc $(GCC_FLAGS) -c $(HEAP_PATH)operations.c $(HEAP_PATH)operations.h