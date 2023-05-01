#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


int main() {
    DynamicTable *heap = malloc(sizeof(DynamicTable));
    initialize_table(heap);

    append_to_table(heap, 1);
    append_to_table(heap, 5);
    
    print_table(heap);
    
    max_heapify(heap, 0);

    print_table(heap);

}