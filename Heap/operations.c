#include "operations.h"
#include <stdio.h>

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
    if (l <= arr->num_elements + 1 && arr->array[l] > arr->array[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= arr->num_elements + 1 && arr->array[r] > arr->array[largest]) {
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
 * Turn regular dynamic table arr into a max heap
 */
void build_max_heap(DynamicTable *arr) {
    for (int i = arr->num_elements / 2; i > 0; i--) {
        max_heapify(arr, i);
    }
}