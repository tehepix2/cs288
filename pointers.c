#include <stdio.h>
#include <stdlib.h>

int main() {
    // how to declare double pointers.
    // int var = 10;
    // int *ptr = &var;
    // int **ptr2 = &ptr;

    // printf("%d", var);
    // printf("%d", *ptr);
    // printf("%d", **ptr2);

    // dynamic multi-dimensional arrays / jagged arrays
    // we use array of pointers using pointers to pointers.

    // array of pointers? tf is that
    // its an array of pointers stupid

    // each element in the array is a pointer (no way)

    // now lets make one

    int *arr[5]; // array of pointers of length 5
    // since arrays are already pointers, this is actually a pointer to pointer already
    // i have an array of 5 elements, and each element is a pointer to an integer.
    // same as int **arr = (int *)malloc(sizeof(int *) * 5); except you can control the size of this one

    for (int i = 0; i < 5; i++) {
        arr[i] = (int *)malloc(sizeof(int)); // allocate a size to every pointer in the array
        *arr[i] = i; // make the pointer in this position equal to i.
    }

    for (int i = 0; i < 5; i++) {
        printf("Memory: %p \n", arr[i]); // this will print the memory locations of every pointer
        printf("Value: %d \n", *arr[i]); // dereference to print numbers.
        // this all works the same way even when using the **arr method.
    }
    printf("\n--------------------------\n\n");

    // now lets make a jagged 2-d array
    int rows = 2;
    int columns = 4;
    
    int **matrix = (int **)malloc(sizeof(int *) * rows); 
    // matrix is a double pointer
    // malloc(sizeof(int *) * rows) allocate the size of an integer pointer * the number of rows, so make space for two pointers that point to integers.
    // (int **) cast this to a double pointer, so now matrix points to the first pointer in the memory allocated.

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * columns + i); // allocate memory to every pointer in matrix by a factor of the num of columns + 1 to make it jagged. pointer 1 will be size 16, pointer two will be size 20.
        // since ptr 1 is size 16, it can store 4 integers.
        // since ptr 2 is size 20, it can store 5 integers.
        // we now have a jagged array.

    }
    for (int i = 0; i < rows; i++) { // go through each pointer (rows)
        for (int j = 0; j < columns + i; j++) { // go through each element in every pointer by columns + i (since we did that previously to make the jagged array)
            matrix[i][j] = (i + 1)*j; // assign (i + 1) * j to each memory block in each pointer of the array
        }
    }
    for (int i = 0; i < rows; i++) { // the same loop but print everything
        for (int j = 0; j < columns + i; j++) {
            printf("%d \n", matrix[i][j]);
        }
    }
}