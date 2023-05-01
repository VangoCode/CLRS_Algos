#include <stdio.h>
#include <stdlib.h>

#include "dynamic_table.h"

int main() {
    DynamicTable *table = malloc(sizeof(DynamicTable));

    initialize_table(table);

    print_table(table);
    
    append_to_table(table, 5);
    append_to_table(table, 10);

    print_table(table);

    printf("Now, the table is of size %d\n", table->size);

    append_to_table(table, 15);

    print_table(table);

    printf("Now, the table is of size %d\n", table->size);
    
    pop_from_table(table);
    print_table(table);
    pop_from_table(table);
    print_table(table);

    printf("And now, the table is of size %d\n", table->size);
    
    free(table);
}