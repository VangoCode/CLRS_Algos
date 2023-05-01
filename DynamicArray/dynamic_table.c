#include <stdlib.h>
#include "dynamic_table.h"

/*
 * Initialize an empty dynamic table
 */
void initialize_table(DynamicTable *table) {
    table->size = 1;
    table->num_elements = 0;
    table->array = malloc(sizeof(int) * 1);
    table->array[0] = 0; // initialize as ""null"""
}

/*
 * Double table size
 */
void double_table_size(DynamicTable *table) {
    // Note: var << 1 is the same as doubling it!
    int *old_table = table->array;
    table->array = malloc(sizeof(int) * (table->size << 1));
    
    for (int i = 0; i < table->num_elements; i++) {
        table->array[i] = old_table[i];
    }
    for (int i = table->num_elements; i < (table->size << 1); i++) {
        table->array[i] = 0;
    }

    free(old_table);

    table->size = (table->size << 1);
}

/*
 * Halve table size
 * Precondiiton:
 *      - table->num_elements == (table->size / 2)
 */
void halve_table_size(DynamicTable *table) {
    // Note: var >> 1 is the same as halving it!
    int *old_table = table->array;
    table->array = malloc(sizeof(int) * (table->size >> 1));

    for (int i = 0; i < table->num_elements; i++) {
        table->array[i] = old_table[i];
    }

    free(old_table);
    table->size = (table->size >> 1);
}

/*
 * Append to a dynamic table
 */
void append_to_table(DynamicTable *table) {

}

/*
 * Pop from a dynamic table
 */
void pop_from_table(DynamicTable *table) {

}