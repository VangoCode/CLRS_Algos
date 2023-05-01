GCC_FLAGS= -Wall -Werror -g -std=gnu99

dynamic_array : dynamic_array.o dynamic_table.o dynamic_table.h
	gcc $(GCC_FLAGS) -o dynamic_array dynamic_array.o dynamic_table.o

dynamic_array.o : dynamic_array.c dynamic_table.h
	gcc $(GCC_FLAGS) -c dynamic_array.c dynamic_table.h

dynamic_table.o : dynamic_table.c dynamic_table.h
	gcc $(GCC_FLAGS) -c dynamic_table.c dynamic_table.h
