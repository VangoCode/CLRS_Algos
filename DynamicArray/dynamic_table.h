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
 * Append item to Dynamic Table table
 */
void append_to_table(DynamicTable *table, int item);

/*
 * Pop from Dynamic Table table
 */
int pop_from_table(DynamicTable *table);

/*
 * Print all the elements of the dynamic table in an array-like format
 */
void print_table(DynamicTable *table);