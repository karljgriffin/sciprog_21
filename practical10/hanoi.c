#include <stdio.h>
#include <stdlib.h>

// Problem
//
// Rod 1 = A
// Rod 2 = B
// Rod 3 = C
//
// n disks = 2
//
// Disk 1 from A to B
// Disk 2 from A      to C
// Disk 1 from      B to C
//
// Shift 'n-1' disks from Source (A) to Middle (B)
// Shift one disk from Source (A) to Destination (C)
// Shift 'n-1' disks from Middle (B) to Destination (C)

void hanoi(int n, int source, int dest, int midd) {

	if (n == 1) {
		printf("Moved disk %d from %d to %d\n", n, source, dest);
	}
	else {
		hanoi(n-1, source, midd, dest);
		printf("Moved disk %d from %d to %d\n", n, source, dest);
		hanoi(n-1, midd, dest, source);
	}
	
}

void main() {

	int h;
	printf("Enter number of disks: \n");
	scanf("%d", &h);
	printf("Tower of Hanoi solution for %d disks:\n", h);
	hanoi(h,1,3,2);

}