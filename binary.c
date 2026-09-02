#include <unistd.h>
#include <stdio.h>

int main() {
    // bash command using unistd.h (unix library)
    int var = -10;
    char letter = '65';
    printf("Set breakpoint here: %d", letter);
    return 0;

}
// Data:
/*
int
char
float
variables
arrays -> multi-dimensional
structs
functions


integers
*/

// using gdb, use the x command to represent things in binary
// x/1tw &var -> x/(one variable)(binary)(4 bytes) &(variable) 

// negative values are stored using two's complement
// you invert the bits and add one
// int var = 10; -> 000001010
// int var = -10; -> 111110101 -> + 1 -> 111110110
// wednesday quiz