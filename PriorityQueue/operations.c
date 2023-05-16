#include <stdio.h>
#include <stdlib.h>
#include "operations.h"


/*
 * Return what is at the front of the priority queue
 */
int priority_queue_peek(PriorityQueue *priority_queue) {
    DynamicTable *heap = priority_queue->heap->heap;
    if (heap->num_elements == 0) {
        // no elements in the queue
        return 0;
    }
    return heap->array[1]; // return top element
}

/*
 * Extract from priority queue
 */
int priority_queue_extract(PriorityQueue *priority_queue) {
    DynamicTable *heap = priority_queue->heap->heap;
    if (heap->num_elements < 1) {
        // no elements in the queue
        return 0;
    }
    int maximum = heap->array[1];
    heap->array[1] = heap->array[heap->num_elements];
    heap->num_elements--;
    priority_queue->heap->heapify(heap, 1);
    return maximum;
}

/*
 * Update the position of the key in the priority queue
 */
void priority_queue_update_key(PriorityQueue *priority_queue, int key) {
    DynamicTable *heap = priority_queue->heap->heap;
    append_to_table(heap, key);
}

/*
 * Insert into the priority queue
 */
void priority_queue_insert(PriorityQueue *priority_queue, int key) {
    DynamicTable *heap = priority_queue->heap->heap;
    heap->num_elements++;
    heap->array[heap->num_elements] = -1;
    priority_queue_update_key(priority_queue, key);
}


/*
 * Initialize an empty priority queue
 */
void initialize_priority_queue(PriorityQueue *priority_queue, void (*heapify)(DynamicTable *, int)) {
    priority_queue->heap = malloc(sizeof(Heap));
    if (priority_queue->heap == NULL) {
        perror("malloc error");
        exit(1);
    }
    initialize_heap(priority_queue->heap, heapify);
}