#include <stdio.h>
/* This code calculates the sum 1/1 + 1/2 + 1/3 + ... + 1/1000 */

	int main(void) {
	/* Declare variables */
	int i;
	float sum1, sum2, diff;
	/* First sum */
	sum1 = 0.0;
	for (i=1; i<=1000; i++) {
		/* Make the index to a float value, calculate the fraction 1/i and add it to the sum */
		float floati;
		floati = (float) i;
		sum1 = sum1 + 1.0/floati;
	}
	/* Second sum */
	sum2 = 0.0;
	for (i=1000; i>0; i--) {
                /* Make the index to a float value, calculate the fraction 1/i and add it to the sum */
                float floati;
                floati = (float) i;
                sum2 = sum2 + 1.0/floati;
	}
	printf(" Sum1=%f\n",sum1);
	printf(" Sum2=%f\n",sum2);
	/* Find the difference */
	diff = /* ?? */
	printf(" Difference between the two is %f\n",diff);
}

