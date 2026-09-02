#include <stdio.h>
#define SIZE 10
void bubble(int *, int, int (*compare)(int, int));

void swap(int *, int *);

int ascending(int a, int b) {
    return a > b;
}
int descending(int a, int b) {
    return b > a;
}

int main() {
    int arr[SIZE] = {6, 4, 7, 2, 5, 9, 1, 1, 1, 8};
    printf("Before sorting: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\nAfter sorting: \n");
    bubble(arr, SIZE, ascending);
    for (int i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }
}

void bubble(int *array, int size, int (*compare)(int, int)) { // bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            /*if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }*/
           if ((*compare)(array[j], array[j+1])) { // using func pointer, pretty much replaces the block of code here with b > a or a > b
                swap(&array[j], &array[j+1]);
           }
        }
    }
}

void swap(int *element1, int *element2) { // swap function
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}