#include <stdio.h>

//function pointers????!!!!!!
int cube(int n) {
    return n*n*n;
}

int square(int n) {
    return n*n;
}

int (*fptr)(int); // function pointer

int main() {
    // pointers that hold the memory address of another function.
    // function pointers are very powerful because your program can dynamically
    // determine which function to be called during the execution of the program.
    /*int x = 10;
    fptr = cube; // dont need & since function name itself is a pointer
    printf("%d\n", fptr(3));
    printf("%d\n", fptr(4));
    */
    // dynamically call functions???
    int var;
    scanf("%d", &var);
    if (var == 0) {
        fptr = cube;
    }
    else {
        fptr = square;
    }
}