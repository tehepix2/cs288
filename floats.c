#include <stdio.h>
void radix_sort(unsigned int A[], unsigned int n, int b) { // A is the array, n is the amount of items in the array, and b is the number of bits.
    //create two buckets.
    unsigned int bucket0[n], bucket1[n];
    unsigned int mask, count0, count1;
    // iterate through the bits.
    
    for (int i = 0; i < b; i++) {
        mask = 1 << i;
        count0 = 0; //reset the counts
        count1 = 0;
        // sort array A using d-th bit as the key.
        for (int k = 0; k < n; k++) { 
            if (A[k] & mask) { // take the k-th element and do bitwise & with 1 left shifted k times. you get a 0 or 1 from the expression so no comparison with 0 needed
                bucket1[count1++] = A[k]; // count1 keeps track of the position of bucket 1
                
            } else {
                bucket0[count0++] = A[k]; // count0 keeps track of position of bucket 0.
            }
        }
        // now join the buckets (in reverse order for floats)
        for (int i = 0; i < count1; i++) {
            A[i] = bucket1[i];
        }
        for (int i = 0; i < count0; i++) {
            A[i + count1] = bucket0[i]; // add count0 to continue after the first bucket
        }
    }
}
int main() {
    // representation of floating point nums:
    //   _  _______ ______________________ < 32 bits
    // Sign Exponent fractional
    // 1st bit is the sign (pos or neg) next 23 bits say the exponent, and the last part
    // is a fractional value
    // 0 | 0 1 1 1 1 1 0 0 | 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 = 0.15625
    // sign (pos 0) | exponent (8 bits) | fraction (23 bits)
    // how to radix sort them?

    // bitwise only work on ints, so you need to cast it.
    // two's complement is not used for negative floats.
    /* 
    non-negative float radix sort:
    larger bit/digit means larger value.
    when joining buckets, join the 0 bucket and then the 1 bucket.

    0.15625 -> 0 01111100 01000000..00 
    0.21875 -> 0 01111100 11000000..00
    so sorting positive floats is the exact same as sorting regular unsigned ints.
    */
    /*
    now negative float points:
    larger bit/digit means a smaller value.
    so join the larger bit and then the smaller bit.
    pretty much just switch the order in which you join the buckets.
    */
    float array[] = {-3.14159, -0.0078125, -128.5, -9876.543, -6.022e23, -1.618, -0.0, -1.0};
    unsigned int length = sizeof(array) / sizeof(array[0]);
    int num_bits = sizeof(int) * 8;

    radix_sort(array, length, num_bits);

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
}