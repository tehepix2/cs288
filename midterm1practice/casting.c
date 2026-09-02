#include <stdio.h>

int main() {
    int x = 1057;
    char *ptr = (char *)&x;

    printf("%c \n", *ptr);
}