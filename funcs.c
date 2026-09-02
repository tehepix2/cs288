#include <stdio.h>
#include <stdlib.h>

int cube(int n) { // makes a copy of the variable passed
    return n*n*n;
};

void cubes(int *n) {
    *n = *n * *n * *n; // directly changes the value of whatever was passed through
}
int main() {
    // many functions use address as parameters
    // it is more useful when we pass the address 
    // to a function instead of copying all the data to a function
    int x = 10;
    int result = cube(x);
    printf("%d", result);
    cubes(&x);
    printf("%d", x);
}