#include <stdio.h>
#include <math.h>

int main(void) {
	/* Declare variables */
	int i, N;
	float sum, a, b, x, value, diff;
	/* Set constants */
	a = 0;
	b = M_PI / 3.0;
	N = 12;
	/* Calculate integral by summing over discrete values over whole range */
	sum = tan(a) + tan(b);   /* Initialize sum with first and last value */
	for (i=1; i<N; i++) {
		x = a + (b-a)/N * i;	/* Next x value */
		value = 2.0 * tan(x);	/* Function value */
		sum = sum + value;
		printf(" %.2d: x: %.3f   sum: %.3f\n", i, x, sum);
	}
	sum = sum * (b-a)/(2.0*N); 	/* Calculate final integral approximation */
	printf(" Integral = %f\n",sum);
	diff = sum - logf(2);
	printf(" Difference to log(2): %f\n", diff);
	printf(" Done!\n");
}

