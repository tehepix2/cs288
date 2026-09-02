#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) { // argv is an array of pointers. (same as **argv[])
    // argc is the number of arguments. the argv is the array 
    // that stores the arguments. (they can be named anything but must be in this order)
    // envp stores environment variables.
    // an example of dynamic multi-dimentional arrays are the commandline args in C.
    // strings are just an array of characters that end with delimiter NULL to signify its end. 

    // char str[] = "abcd";
    // printf("%lu\n", sizeof(str)); // this prints 5 but there are 4 characters, due to the extra NULL at the end.
    // printf("%d \n", str[4]);

    // while (argc-- > 0) { // print commandline arguments
    //     printf("%s \n", argv[argc]);
    // }
    // int index = 0;
    // while(envp[index]) {
    //     printf("%s \n", envp[index]);
    //     index++;
    // }
    // the third parameter just gives you all of the environment variables, so it wont affect using commandline arguments.
    
    // the strtok (part of the <string.h> library.) allows to split a string into multiple tokens using your own delimiter (instead of \0)

    char str[] = "cdl26@njit.edu:home/cs288/summer/2026";
    char delimeter[] = "@/:=."; // set a delimiter(s)
    char *token = strtok(str, delimeter); // (strtok returns a pointer.) 
    // it works by replacing each delimeter with a \0.
    printf("%s \n", token);

    while (token != NULL) { // goes through every part of the string based on all of the delimeters.
        printf("%s \n", token);
        token = strtok(NULL, delimeter);
    }
    
    // now, what if i want to get just the environment variables without their values?
    // int index = 0;
    // char *token2;
    // char delimeter2[] = "="; // this can be longer than =, you can add as many as you want.
    // while( envp[index] ) {
    //     token2 = strtok(envp[index], delimeter2); // first argument is the string, second is the delimeter.
    //     printf("%s \n", token2);
    //     index++; 
    // }
    // this will print the names of all the environment variables.
    // printf("%s", token2);

    // set env:
    char *setenv(char *name, char *value, int overwrite);
    // get env:
    char *getenv(char *name);
    // unset env: (does not actually delete your environment variables)
    char *unsetenv(char *name);
    return 0;
}