/*
 *Iterative and Recursive version of Euclid's Algorithm
 *to calculate the gcd of two positive integers
 */
 
#include <stdio.h>

//First function will be iterative
//a and b below are arguments to this function, i.e.
//they are local to this function and are independent
//of a and b in main function
//This is function declaration
int iterativeGCD(int a, int b);

int recursiveGCD(int a, int b) {
	if (b==0) {
		return a;
	}
	else {
		return(recursiveGCD(b, a%b));
		//Calls itself
	}
}

int main(void) {

   int a, b, error;

   printf("Please input two positive integers\n");
   error = scanf("%d %d",&a,&b);
   if (error != 2) {
     printf("Please try again\n");
     return 1;
   }

   if (a<=0 || b<=0) {
     printf("These numbers are not positive!\n");
     return 1;
   }
   
   //Call functions
   printf("Iterative GCD(%d, %d)=%d\n", a, b, iterativeGCD(a,b));
   //Above - calling function from within the printf

   printf("Recursive GCD(%d, %d)=%d\n", a, b, recursiveGCD(a,b));

  return 0;
}

//Function definition
int iterativeGCD(int a, int b) {

	int temp;
	while(b != 0) {
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}



