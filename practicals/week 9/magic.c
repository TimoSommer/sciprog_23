#include <stdio.h>
#include <stdlib.h>

// Declare functions
int *allocatearray(int n);
void fillwithones(int *array, int size);
void printarray(int *array, int size);
void freearray(int *array);

int main(void) {
    // Declare variables
    int size, maxsize, *array;
    maxsize = 5;

    // Run the program with different array sizes
    for (size=3; size<=maxsize; size++){
        printf("\nPrinting array of size %d...\n", size);

        // Allocate memory for an array, fill it with ones, print and free the memory.
        array = allocatearray(size);
        fillwithones(array, size);
        printarray(array, size);
        freearray(array);
    }
    return 0;
}

int *allocatearray(int n){
    // Allocates memory for an array and returns its pointer.
    int *p;
    p = (int *) malloc(n * sizeof(int));
    return p;
}
void freearray(int *array){
    // Frees the memory from an array.
    free(array);
    printf("Array memory was freed.\n");
}
void fillwithones(int *array, int size){
    // Fills an array with ones.
    int i;
    for (i=0; i<size; i++){
        array[i] = 1;
    }
}
void printarray(int *array, int size){
    // Prints a 1-dimensional array with given size.
    int i;
    printf("Array:\n");
    for (i=0; i<size; i++){
        printf("%d  ", array[i]);
    }
    printf("\n");
}

