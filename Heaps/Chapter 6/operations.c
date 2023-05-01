#include "operations.h"

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
   return (2 << i) + 1; // left shift once, add one to get right child
}