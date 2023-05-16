#include "../Heap/operations.h"
#define MIN_PRIORITY_QUEUE min_heapify
#define MAX_PRIORITY_QUEUE max_heapify

typedef struct priority_queue {
    Heap *heap;
} PriorityQueue;


/*
 * Return what is at the front of the priority queue
 */
int priority_queue_peek(PriorityQueue *priority_queue);

/*
 * Extract from priority queue
 */
int priority_queue_extract(PriorityQueue *priority_queue);

/*
 * Insert into the priority queue
 */
void priority_queue_insert(PriorityQueue *priority_queue, int key);

/*
 * Update the position of the key in the priority queue
 */
void priority_queue_update_key(PriorityQueue *priority_queue, int key);

/*
 * Initialize an empty priority queue
 */
void initialize_priority_queue(PriorityQueue *priority_queue, void (*heapify)(DynamicTable *, int));