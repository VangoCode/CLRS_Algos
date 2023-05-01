#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int A[5] = {0, 0, 0, 0, 0}; // heap for testing purposes

int main() {
    printf("Hello world\n");  
    printf("The parent of index %d is %d\n", 5, parent(5));  
    printf("The left child of index %d is %d\nThe right child of index %d is %d\n", 5, left(5), 5, right(5));
}