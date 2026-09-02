#include <stdio.h>

int main() {
	//int arr[10];
	//int index = -876543210;
	//arr[index] = 1234;
	// compile program using gcc -g cstuff.c
	// then run gdb ./a.out to run debugger
	// enter "run" into the prompt to run the program
	// enter "list" to see all of the code and their lines
	//printf("The value at index is : %d", arr[index]);
	//return 0;
	//

	int num;
	int result = 1;
	printf("Enter a number: ");
	scanf("%d", &num);
	//use break [line num} to set breakpoint
	for (int i = 1; i <= num; i++) {
		result *= num;
		num--;
	}
	printf("The factorial is: %d ", result);
}

