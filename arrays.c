#include <stdlib.h>
#include <stdio.h>

int main() {
    int arr3[3][2];
    int value2 = 1;
    
    for (int i = 0; i < 3; i++) {
        for (int j=0; j<2; j++) {
            arr3[i][j] = value2;
            value2++;
        }
    }
    // pointer casting
    int x = 10;
    int *ptr = (int *)&x; // interpret x as an int
    printf("%d\n", *ptr);

    int y = 43;
    char *ptr2 = (char *)&y;
    printf("%c\n", *ptr2); // treat y as a char, prints +

    float f = 123.45;
    int a = (int)f;
    int *b = (int *)&f;
    // a is just being regularly casted to be 123, but pointer b is recieving the literal binary that represents f, 
    // so you get a giant number.
    printf("%f\n", f);
    printf("%d\n", a);
    printf("%f\n", *b);

    // back to 2d arrays to 1d arrats
    int *arr = (int *)arr3; // cast whole array as pointer to integer
    for (int i=0;i<6;i++) {
        printf("%d\n", *(arr + i)); // print elements using pointer arithmetic
    }
}