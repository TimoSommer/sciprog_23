#include <stdio.h>
#include <math.h>

/* Declare functions and global variables */
float calculate_tan_integral(int N);
float degtorad(float arg);
float array[13];

int main(void) {
	/* Declare variables */
	int i, N;
	float rad, deg, result, integral;
	
	/* Fill array with Tan(x) values for x in [0,60] with stepsize 5. */
	for (i=0; i<=12; i++) {
		deg = 5. * i;
		rad = degtorad(deg);		
		result = tan(rad);
		array[i] = result;
		printf(" deg: %.3f   rad: %.3f   tan: %.3f\n", deg, rad, result);
	}
	
	/* Calculate the integral of the Tan as last week, but now as subroutine */
	integral = calculate_tan_integral(100);
	printf("Integral: %.2f\n", integral);
}


float calculate_tan_integral(int N){
        /* Declare variables */
        int i;
        float sum, a, b, x, value, diff;

        /* Set constants */
        a = degtorad(0);
        b = degtorad(60);

        /* Calculate integral by summing over discrete values over whole range */
        sum = tan(a) + tan(b);   /* Initialize sum with first and last value */

        for (i=1; i<N; i++) {
                x = a + (b-a)/N * i;    /* Next x value */
                value = 2.0 * tan(x);   /* Function value */
                sum = sum + value;
        }
        sum = sum * (b-a)/(2.0*N);      /* Calculate final integral approximation */

	return sum;
}

float degtorad(float arg) { return( (M_PI * arg)/180.0 );
}
