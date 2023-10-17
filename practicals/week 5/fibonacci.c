#include <stdio.h>
#include <math.h>

/* Declare functions and global variables */
void fibonacci(long *Fn1, long *Fn2);

int main(void) {
	/* Declare variables. Fn1 means F_(n-1), Fn2 means F_(n-2). */
	long i, n, Fn, Fn1, Fn2;

	/* Take user input */
	printf("Enter an int to calculate the nth element of the Fibonacci series:\n");
	scanf("%d",&n);
	
	/* Initialize array to keep the Fibonacci sequence. Inialize F0 and F1. */
	long array[n];
	array[0] = 0;
	array[1] = 1;	
	
	/* Fill array with the following numbers of the Fibonacci sequence up to the specified n. */
	for (i=2; i<n; i++) {
		Fn1 = array[i-1];
		Fn2 = array[i-2];
		fibonacci(&Fn1, &Fn2); /* pass by reference, change Fn-1 and Fn-2 to Fn and Fn-1 */
		Fn = Fn1;
		array[i] = Fn;
	}

	/* Print the Fibonacci sequence from the array */
	for (i=0; i<n; i++){
		printf(" n: %d   Fn: %d\n", i, array[i]);
	}
	
}

void fibonacci(long *Fn1, long *Fn2){
	/* Change the two input numbers to become the next highest numbers in the Fibonacci series. */
	long tmp;
	tmp = *Fn1;
	*Fn1 = *Fn1 + *Fn2;
	*Fn2 = tmp;	
}

