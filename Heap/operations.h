#include "../DynamicArray/dynamic_table.h"

typedef struct heap {
    void (*heapify)(DynamicTable *, int); // max or min heapify
    void (*build_heap)(DynamicTable *);
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
 * Turn regular dynamic table arr into a max heap
 */
void build_max_heap(DynamicTable *arr);

/*
 * Sort an array using heapsort
 */
void heapsort(Heap *heap);


/*
 * Generic, turn a Heap data type into a min or max-heap based on specified heapify function
 */
void build_heap(Heap *heap);