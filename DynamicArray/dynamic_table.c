#include <stdio.h>
#include <stdlib.h>
#include "dynamic_table.h"

/*
 * Initialize an empty dynamic table
 */
void initialize_table(DynamicTable *table) {
    table->size = 1;
    table->num_elements = 0;
    table->array = malloc(sizeof(int) * (1 + 1));
    table->array[0] = 0; // initialize as ""null"""
    table->array[1] = 0;
}

/*
 * Double table size
 */
void double_table_size(DynamicTable *table) {
    // Note: var << 1 is the same as doubling it!
    int *old_table = table->array;
    table->array = malloc(sizeof(int) * ((table->size << 1) + 1));
    
    for (int i = 0; i <= table->num_elements; i++) {
        table->array[i] = old_table[i];
    }
    for (int i = table->num_elements + 1; i < (table->size << 1) + 1; i++) {
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
    table->array = malloc(sizeof(int) * ((table->size >> 1) + 1));

    for (int i = 0; i < table->num_elements + 1; i++) {
        table->array[i] = old_table[i];
    }

    free(old_table);
    table->size = (table->size >> 1) + 1;
}

/*
 * Append to a dynamic table
 */
void append_to_table(DynamicTable *table, int item) {
    if (table->size == table->num_elements) {
        double_table_size(table);
    }
    table->array[table->num_elements + 1] = item;
    table->num_elements++;
}

/*
 * Pop from a dynamic table
 */
int pop_from_table(DynamicTable *table) {
    if (table->size == (table->num_elements << 1)) {
        halve_table_size(table);
    }
    table->num_elements--;
    return table->array[table->num_elements + 2];
}

/*
 * Print all the elements of a dynamic table in an array-like format
 */
void print_table(DynamicTable *table) {
    printf("[ ");
    for (int i = 1; i < table->num_elements + 1; i++) {
        printf("%d ", table->array[i]);
    }
    printf("]\n");
}