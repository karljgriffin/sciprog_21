#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"
//Above - because we have a header file in this directory, we use quotation marks
//The thing we are looking for is local

//Need a function here that will get the number of lines in our file
int getlines(char filename[MAX_FILE_NAME]);

int main() {

	//int n;
	//printf("Enter the square size:\n");
	//scanf("%d", &n);
	
	//Open the file
	FILE *f;
	char filename[MAX_FILE_NAME];
	printf("Enter file name: ");
	scanf("%s", filename);
	
	//Do not forget!
	f = fopen(filename, "r");
	
	int n = getlines(filename);
	
	//Allocate a matrix
	//We want to have this as an array of pointers, where each pointer is a row
	int i;
	int ** magicSquare = malloc(n * sizeof(int*));
	
	for(i = 0; i < n; i++) {
		magicSquare[i] = malloc(n * sizeof(int));
	}
	
	int j;
	
	for(i = 0; i < n; i++) {
		//printf("Enter the elements in row #%d, separated by blanks and/or linebreaks:\n", i+1);
		for(j = 0; j < n; j++) {
			fscanf(f, "%d", &magicSquare[i][j]); 
		}
	}
	
	printf("The square %s magic.\n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");
	
	//Now free each row separately before we free the pointers
	for(i = 0; i < n; i++) {
		free(magicSquare[i]);
	}
	free(magicSquare);
	
	fclose(f); 
	
	return 0;

}

int getlines(char filename[MAX_FILE_NAME]) {

	//Point to a location in memory where our file is stored
	FILE *fp;
	fp = fopen(filename, "r");
	
	int ch_read;
	int count = 0;
	
	while( (ch_read = fgetc(fp)) != EOF)
	{
		if (ch_read == "\n") {
			count++;
		}
	}
	
	printf("No. of lines %d\n", count);
	fclose(fp);
	return count;

}




