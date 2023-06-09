#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Return the index of the parent of the element in the heap. Assumes you are 1-indexed
 */
int parent(int i) {
    return i >> 1; // right shift once to divide by 2 floored
}

/*
 * Return the index of the left subchild of the element in the heap. Assumes you are 1-indexed
 */
int left(int i) {
    return i << 1; // left shift once to multiply by 2
}

/* 
 * Return the index of the right subchild of the element in the heap. Assumes you are 1-indexed
 */
int right(int i) {
   return (i << 1) + 1; // left shift once, add one to get right child
}

/*
 * Perform max heapify onto integer array arr
 */
void max_heapify(DynamicTable *arr, int i) { 
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < arr->num_elements + 1 && arr->array[l] > arr->array[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < arr->num_elements + 1 && arr->array[r] > arr->array[largest]) {
        largest = r;
    }
    if (largest != i) {
        int tmp = arr->array[i];
        arr->array[i] = arr->array[largest];
        arr->array[largest] = tmp;
        max_heapify(arr, largest);
    }
}

/*
 * Perform min heapify onto integer array arr
 */
void min_heapify(DynamicTable *arr, int i) {
    int l = left(i);
    int r = right(i);
    int smallest;
    if (l < arr->num_elements + 1 && arr->array[l] < arr->array[i]) {
        smallest = l;
    } else {
        smallest = i;
    }
    if (r < arr->num_elements + 1 && arr->array[r] < arr->array[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        int tmp = arr->array[i];
        arr->array[i] = arr->array[smallest];
        arr->array[smallest] = tmp;
        min_heapify(arr, smallest);
    }
}


/**
 GENERIC HEAP FUNCTIONS
**/

/*
 * Used to initialize an empty heap of max or min heapify
 */
void initialize_heap(Heap *heap, void (*heapify)(DynamicTable *, int)) {
    heap->table = malloc(sizeof(DynamicTable));
    heap->heapify = heapify;
    initialize_table(heap->table);
}

/*
 * Generic, turn a Heap data type into a min or max-heap based on specified heapify function
 */
void build_heap(Heap *heap) {
    for (int i = heap->table->num_elements / 2; i > 0; i--) {
        heap->heapify(heap->table, i);
    }
}

/*
 * Generic. Sort an array using heapsort
 */
void heapsort(Heap *heap) {
    build_heap(heap);
    int temp_size = heap->table->num_elements;
    for (int i = heap->table->num_elements; i > 1; i--) {
        int temp = heap->table->array[1];
        heap->table->array[1] = heap->table->array[i];
        heap->table->array[i] = temp;
        heap->table->num_elements--;
        heap->heapify(heap->table, 1);
        int temp2 = heap->table->num_elements;
        heap->table->num_elements = temp_size;
        heap->table->num_elements = temp2;
    }
    heap->table->num_elements = temp_size;
}
