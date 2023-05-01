GCC_FLAGS= -Wall -Werror -g -std=gnu99

dynamic_array : dynamic_array.o 
	gcc $(GCC_FLAGS) -o dynamic_array dynamic_array.o

dynamic_array.o : dynamic_array.c
	gcc $(GCC_FLAGS) -c dynamic_array.c
