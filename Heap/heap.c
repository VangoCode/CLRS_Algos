#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


int main() {
    // test for now, will refactor in next update
    Heap *heap = malloc(sizeof(heap));
    heap->heap = malloc(sizeof(DynamicTable));
    heap->heapify = min_heapify;
    // initialize_heap?
    initialize_table(heap->heap);

    append_to_table(heap->heap, 5);
    append_to_table(heap->heap, 1);
    append_to_table(heap->heap, 3);
    append_to_table(heap->heap, 2);
    append_to_table(heap->heap, 4);
    
    printf("Here is the array before we build it into a max-heap:\n");

    print_table(heap->heap);
    
    // build_max_heap(heap->heap);
    // test:
    build_heap(heap);

    printf("Here it is after:\n");

    print_table(heap->heap);

    printf("And now here it is after we run heapsort on it:\n");

    heapsort(heap);

    print_table(heap->heap);



}