#include <stdio.h>
#include <stdlib.h>

#include "dynamic_table.h"

int main() {
    DynamicTable *table = malloc(sizeof(DynamicTable));
    // // to initialize the dynamic table
    // table->size = 0;
    // table->num_elements = 0;
    // table->array = NULL;


    initialize_table(table);
    printf("Initially, the table is of size %d\n", table->size);
    double_table_size(table);
    double_table_size(table);
    printf("Now, the table is of size %d\n", table->size);
    halve_table_size(table);
    printf("And now, the table is of size %d\n", table->size);
    
    free(table);
}