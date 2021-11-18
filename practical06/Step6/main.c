#include <stdio.h>

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main() {

	int n=5, p=3, q=4;
	//Arrays below are static arrays, i.e. size is fixed
	double A[n][p], B[p][q], C[n][q];
	//Below are the loop indices
	int i, j, k; 
	
	//Initialise A, B, C matrices
	//2-D arrays so we will need two loops to initialise them, i.e. nested loops
	for(i=0; i<n; i++) {
		for (j=0; j<p; j++) { 
			A[i][j]=i+j;
		}
	}
	for(i=0; i<p; i++) {
		for (j=0; j<q; j++) { 
			B[i][j]=i-j;
		}
	}
	for(i=0; i<n; i++) {
		for (j=0; j<q; j++) { 
			C[i][j]=0.0;
		}
	}
	//Perform matrix multiplication
	matmult(n, p, q, A, B, C);
	
	//Comment this out as we are calling it from the mm.c file
	/*for(i=0; i<n; i++)
		for(j=0; j<q; j++)
			for(k=0; k<p; k++)
				C[i][j]=C[i][j]+A[i][k]*B[k][j];*/
				
	//Print out the matrices
	printf("\nThis is matrix A:\n\n");
	for(i=0; i<n; i++) {
		for(j=0; j<p; j++) {
			printf("%3.0f", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThis is matrix B:\n\n");
	for(i=0; i<p; i++) {
		for(j=0; j<q; j++) {
			printf("%3.0f", B[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThis is matrix C:\n\n");
	for(i=0; i<n; i++) {
		for(j=0; j<q; j++) {
			printf("%3.0f", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}