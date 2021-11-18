#include <stdio.h>

int main(void) {

	int i;
	double a;
	printf("Enter an int and a double, separated by (,)\n");
	scanf("%d, %lf", &i, &a);
	//for scanf the addresses of the variables are passed
	//if ampersands above are removed we get a segmentation fault, happens when memory is not allocated correctly
	printf("You have entered %d, and %lf\n", i, a);
	
	//define a pointer variable
	//pointers are integer values which hold a memory address
	int *pointer_to_i = &i; 
	printf("The value i is %d\n", i);
	printf("The value i is also %d\n", *pointer_to_i);
	//Only the reference below stores the memory address, which is stored as an integer value
	printf("The address of i is %d\n", &i);
	
	return 0;
}