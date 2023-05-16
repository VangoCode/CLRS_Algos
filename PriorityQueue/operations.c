#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


/*
 * Return what is at the front of the priority queue
 */
int priority_queue_peek(PriorityQueue *priority_queue) {
    DynamicTable *table = priority_queue->heap->table;
    if (table->num_elements == 0) {
        // no elements in the queue
        return 0;
    }
    return table->array[1]; // return top element
}

/*
 * Extract from priority queue
 */
int priority_queue_extract(PriorityQueue *priority_queue) {
    DynamicTable *table = priority_queue->heap->table;
    if (table->num_elements < 1) {
        // no elements in the queue
        return 0;
    }
    int maximum = table->array[1];
    table->array[1] = table->array[table->num_elements];
    // pop to remove number of elements
    pop_from_table(table);
    priority_queue->heap->heapify(table, 1);
    return maximum;
}

/*
 * Update the position of the key in the priority queue
 */
void priority_queue_update_key(PriorityQueue *priority_queue, int key) {
    DynamicTable *table = priority_queue->heap->table;
    append_to_table(table, key);
    int i = table->num_elements;
    while (i > 1) {
        if (strcmp(priority_queue->type, "MAX") == 0 && table->array[parent(i)] < table->array[i]) {
            int tmp = table->array[i];
            table->array[i] = table->array[parent(i)];
            table->array[parent(i)] = tmp;
        } else if (strcmp(priority_queue->type, "MIN") == 0 && table->array[parent(i)] > table->array[i]) {
            int tmp = table->array[i];
            table->array[i] = table->array[parent(i)];
            table->array[parent(i)] = tmp;
        }
        i = parent(i);
    }
}

/*
 * Insert into the priority queue
 */
void priority_queue_insert(PriorityQueue *priority_queue, int key) {
    priority_queue_update_key(priority_queue, key);
}


/*
 * Initialize an empty priority queue
 */
void initialize_priority_queue(PriorityQueue *priority_queue, void (*heapify)(DynamicTable *, int), char *name) {
    priority_queue->heap = malloc(sizeof(Heap));
    if (priority_queue->heap == NULL) {
        perror("malloc error");
        exit(1);
    }
    priority_queue->type = name;
    initialize_heap(priority_queue->heap, heapify);
}