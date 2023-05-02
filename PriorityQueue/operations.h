#include "../DynamicArray/dynamic_table.h"
#include "../Heap/heap.h"

typedef struct priority_queue {
    void (*insert)(DynamicTable); // insert function
    int (*peak)(DynamicTable); // we are using 'peak' instead of max/min (i.e, look at the front of the queue)
    int (*extract)(DynamicTable); // peak and remove from queue
    int (*increase_key)(DynamicTable); // increase the dynamic table's key
} PriorityQueue;


/*
 * Insert an element into the priority queue
 */
void insert_max();

/*
 *
 */