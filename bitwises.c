#include <stdio.h>

int main() {
    /*
    int a lot of cases, you need a way to manipulate
    specific bits (turning ON/OFF bits) for faster 
    processing and memory efficiency.

    Bit masking:
    a way to manipulate bits at specific positions using 
    bitwise operations.

    0 0 0 0 1 0 1 0
          ^
          |
        n = 4, what if i wanted to make this bit 1?
    Lets say we have the value 10. 
    If you want to turn on a bit, always go with bitwise OR.
    If you want to turn off a bit, always go with bitwise AND.
    0 0 0 0 1 0 1 0 -> at every bit position, replace with 1 1 1 1 1 1 1 1 bitwise operation OR.
    1 1 1 1 1 1 1 1 
    1 1 1 1 1 1 1 1 -> this turned on all 0's.
    now:
    0 0 0 0 1 0 1 0
    0 0 0 0 0 0 0 0
    0 0 0 0 1 0 1 0 -> bitwise OR on all 0's leaves them untouched.

    now how do we turn on the bit at position 4?
    use OR operation and have 1 on the mask at position 4.
    0 0 0 0 1 0 1 0
    0 0 0 1 0 0 0 0 OR
    0 0 0 1 1 0 1 0 -> position 4 is now turned on. 0 0 0 1 0 0 0 0 is the mask. a mask is a predefined set of bits used to manipulate specific bits.
    */
    unsigned int x = 10;
    int n = 4;
    printf("%d\n", x|16); // prints 26. 16 is the 0 0 0 1 0 0 0 0 mask converted to decimal.
    // now what if i want to manipulate position 25? 2^25 takes too long to calculated...
    // take 1, and left shift 25 times. 1 << 25 = 0000 0000 0000 0000 0000 0000 0000 0001 << 25 = 0000 001 -> 0000 0010 0000 0000 0000 0000 0000 0000. bit mask complete.
    // applying this to previous example: left shift 1 4 times.
    int mask = 1 << n;
    printf("%d\n", x | mask); // this also equals 26.

    /* 
    now to turn off a bit... use AND!!!
    0 0 0 0 1 0 1 0
    1 1 1 1 1 1 1 1 AND
    0 0 0 0 1 0 1 0 -> no change.

    0 0 0 0 1 0 1 0
    0 0 0 0 0 0 0 0 AND
    0 0 0 0 0 0 0 0 -> all bits flipped off.
    now what if i want to turn off position 3?

    0 0 0 0 1 0 1 0
    1 1 1 1 0 1 1 1 -> make all except position 3 a 1.
    0 0 0 0 0 0 1 0 = 2-> position 3 flipped off. this mask is also the complement of 8. use LEFT SHIFT AGAIN!!!!
    1 >> 3 = 0 0 0 0 0 0 0 1 << 3 -> 0 0 0 0 1 0 0 0 -> now take complement -> 1 1 1 1 0 1 1 1 (~)
    */

    int mask2 = ~(1 << 3);
  
    printf("%d", x|mask2);
}