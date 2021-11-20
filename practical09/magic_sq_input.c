#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"
//Above - because we have a header file in this directory, we use quotation marks
//The thing we are looking for is local

int main() {

	int n;
	printf("Enter the square size:\n");
	scanf("%d", &n);
	
	//Allocate a matrix
	//We want to have this as an array of pointers, where each pointer is a row
	int i;
	int ** magicSquare = malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		magicSquare[i] = malloc(n * sizeof(int));
	}
	
	int j;
	
	for(i = 0; i < n; i++) {
		printf("Enter the elements in row #%d, separated by blanks and/or linebreaks:\n", i+1);
		for(j = 0; j < n; j++) {
			scanf("%d", &magicSquare[i][j]);
		}
	}
	
	printf("The square %s magic.\n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");
	
	//Now free each row separately before we free the pointers
	for(i = 0; i < n; i++) {
		free(magicSquare[i]);
	}
	free(magicSquare);
	
	return 0;

}