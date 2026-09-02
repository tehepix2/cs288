#include <stdio.h>
#include <stdlib.h>

void radix_sort(float A[], int n, int b) { 
    
    float bucket0[n], bucket1[n];
    unsigned int mask, count0, count1;
    
    
    for (int i = 0; i < b; i++) {
        mask = 1 << i;
        count0 = 0; 
        count1 = 0;
        
        for (int k = 0; k < n; k++) {

            if ((unsigned int)A[k] & mask) { 
                bucket1[count1++] = A[k]; 
                
            } else {
                bucket0[count0++] = A[k]; 
            }
        }
        
        if (i == 31) {
            for (int i = 0; i < count1; i++) {
                A[i] = bucket1[i];
            }
            for (int i = 0; i < count0; i++) {
                A[i + count1] = bucket0[i]; 
            }
        } else {
            for (int i = 0; i < count0; i++) {
                A[i] = bucket0[i];
            }
            for (int i = 0; i < count1; i++) {
                A[i + count0] = bucket1[i]; 
            }
        }
        
    }
}
int main(int argc, char *argv[]) {
    unsigned int nums = argc - 1;
    float array[nums];
    for (int i = 0; i < nums; i++) {
        array[i] = strtof(argv[i + 1], NULL);
    }
    unsigned int length = sizeof(array) / sizeof(array[0]);
    int num_bits = sizeof(float) * 8;

    radix_sort(array, length, num_bits);

    for (int i = 0; i < nums; i++) {
        printf("%.2f\n", array[i]);
    }

}