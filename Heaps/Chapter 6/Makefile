heaps : heaps.o operations.o operations.h 
	gcc -Wall -Werror -g -std=gnu99 -o heaps heaps.o operations.o

heaps.o : heaps.c operations.h
	gcc -Wall -Werror -g -std=gnu99 -c heaps.c operations.h

operations.o : operations.c operations.h
	gcc -Wall -Werror -g -std=gnu99 -c operations.c operations.h