#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


int main() {
    // test for now, will refactor in next update
    Heap *heap = malloc(sizeof(heap));
    // macro for heaps was defined in initialize_heap !!!
    initialize_heap(heap, MAX_HEAP);

    append_to_table(heap->table, 5);
    append_to_table(heap->table, 1);
    append_to_table(heap->table, 3);
    append_to_table(heap->table, 2);
    append_to_table(heap->table, 4);
    
    printf("Here is the array before we build it into a max-heap:\n");

    print_table(heap->table);
    
    build_heap(heap);

    printf("Here it is after:\n");

    print_table(heap->table);

    printf("And now here it is after we run heapsort on it:\n");

    heapsort(heap);

    print_table(heap->table);



}