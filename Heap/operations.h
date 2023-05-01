#include "../DynamicArray/dynamic_table.h"

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