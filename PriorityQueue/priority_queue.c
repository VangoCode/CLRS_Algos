#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main() {
    PriorityQueue *priority_queue = malloc(sizeof(PriorityQueue));
    initialize_priority_queue(priority_queue, MIN_PRIORITY_QUEUE);

    // insert 5
    priority_queue_insert(priority_queue, 5);
    printf("%d\n", priority_queue_peek(priority_queue));
    priority_queue_insert(priority_queue, 3);
    printf("%d\n", priority_queue_peek(priority_queue));
    priority_queue_insert(priority_queue, 7);
    printf("%d\n", priority_queue_peek(priority_queue));
    priority_queue_insert(priority_queue, 2);
    printf("%d\n", priority_queue_peek(priority_queue));
    priority_queue_insert(priority_queue, 1);
    printf("%d\n", priority_queue_peek(priority_queue));
    print_table(priority_queue->heap->table);
}