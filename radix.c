#include <stdio.h>
#include <stdlib.h>

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
        // now join the buckets
        for (int i = 0; i < count0; i++) {
            A[i] = bucket0[i];
        }
        for (int i = 0; i < count1; i++) {
            A[i + count0] = bucket1[i]; // add count0 to continue after the first bucket
        }
    }
}
int main() {
    /*
    Radix sort!!
    Sort by using raw binary data instead of using comparison sorting algorithms such as bubble and selection sort 
    which usually run on n^2 time...
    This will focus on ascending order.

    Bucket sort:
    distributes a set of elements into several buckets and then sorts them individually.
    To sort N integer values with a range of (L, H)
    This uses H - L + 1 buckets. fast when N is large and range is small. slow when N is small and range is large.

    Instead, use radix sort. Use bucket sort but with binary values. There are only 1's and 0's, so there are always just 2 buckets!
    */

    // Implementing radix sort on unsigned integers
    unsigned int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 65, 13, 89, 100000, 99999, 1};
    unsigned int length = sizeof(array) / sizeof(array[0]);
    int num_bits = sizeof(int) * 8;

    radix_sort(array, length, num_bits);

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }

}