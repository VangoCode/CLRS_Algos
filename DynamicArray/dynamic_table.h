typedef struct dynamic_table {
    int size;
    int num_elements;
    int *array;
} DynamicTable;

/*
 * Initialize an empty dynamic table
 */
void initialize_table(DynamicTable *table);

/*
 * Double table size
 */
void double_table_size(DynamicTable *table);

/*
 * Halve table size
 */
void halve_table_size(DynamicTable *table);

/*
 * Append to a dynamic table
 */
void append_to_table(DynamicTable *table);

/*
 * Pop from a dynamic table
 */
void pop_from_table(DynamicTable *table);