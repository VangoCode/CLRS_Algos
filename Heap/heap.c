#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


int main() {
    DynamicTable *heap = malloc(sizeof(DynamicTable));
    initialize_table(heap);

    append_to_table(heap, 1);
    append_to_table(heap, 2);
    append_to_table(heap, 3);
    append_to_table(heap, 4);
    append_to_table(heap, 5);
    
    print_table(heap);
    
    build_max_heap(heap);

    print_table(heap);

}