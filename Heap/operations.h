#define MIN_HEAP min_heapify
#define MAX_HEAP max_heapify

#include "../DynamicArray/dynamic_table.h"

typedef struct heap {
    void (*heapify)(DynamicTable *, int); // max or min heapify
    DynamicTable *heap; // the heap associated with this heap
} Heap;

/*
 * Return the index of the parent of the element in the heap.
 */
int parent(int i);

/*
 * Return the index of the left subchild of the element in the heap.
 */
int left(int i);

/* 
 * Return the index of the right subchild of the element in the heap.
 */
int right(int i);

/*
 * Perform max heapify onto integer array arr
 */
void max_heapify(DynamicTable *arr, int i);

/*
 * Perform min heapify onto integer array arr
 */
void min_heapify(DynamicTable *arr, int i);

/*
 * Generic. Used to initialize a heap.
 * "MAX_HEAP" is used to initialize a max-heap
 * "MIN_HEAP" is used to initialize a min-heap
 */
void initialize_heap(Heap *heap, void (*heapify)(DynamicTable *, int));

/*
 * Generic. Sort an array using heapsort
 */
void heapsort(Heap *heap);


/*
 * Generic, turn a Heap data type into a min or max-heap based on specified heapify function
 */
void build_heap(Heap *heap);