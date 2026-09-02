#include <stdio.h>

int main() {
    // custom data type that lets you combine multiple data types
    struct record {
        int id; // size 4
        char name[8]; //size 8
        float price; // size 4
        // total size is 16 bytes
    };

    struct record rec1 = {10, "john", 123.45};
    // so a struct is pretty much a custom-made data type.
    // so how is it stored in memory?
    // is is still continuous in the memory.
    // you can access the members using pointer arithmetic!!
    int *field1 = (int *)&rec1;
    // rec1 points to the first member, so *field1 points to 10.
    char *field2 = (char *)&rec1 + 0x4; // add 4 bytes to makeup the difference of the first member which is 4 bytes
    // 0x4 means 4 bytes in hex
    float *field3 = (float *)((char *)&rec1 + 12);

    printf("%d\n", *field1);
    printf("%s\n", field2);
    printf("%f\n", *field3);
}