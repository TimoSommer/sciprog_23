#include <stdio.h>
#include <math.h>

/* Declare functions and global variables */
double artanh1(double x, double delta);
double artanh2(double x);

int main(void) {
	/* Declare variables */
	int i, n;
	double a, b, step, x, nfloat, delta, sumdiffs, acc;
	
	/* Get user input for the precision delta of the Maclaurin series method */	
	printf("Enter a value > 0 as precision for the Maclaurin series calculation:\n");
	scanf("%lf", &delta);
	/* Check that the provided delta is > 0 */
	if (delta <= 0){
		printf("User Input Error: Please provide a value greater than 0.\n");
		return;
	}
	
	/* Get the number of steps for the sampling of x. */
	a = -0.9;
	b = 0.9;
	step = 0.01;
	nfloat = (b-a)/step;
	n = (int) nfloat;
	
	/* Set up arrays with the correct number of entries as just calculated */
	double array1[n+1], array2[n+1];
	
	/* Calculate the artanh(x) using two different methods and add the absolute differences to calculate the accuracy later */
	sumdiffs = 0;
	for (i=0; i<=n; i++){
		x = a + step * i;   /* next step */
		array1[i] = artanh1(x, delta);
		array2[i] = artanh2(x);
		sumdiffs = sumdiffs + fabs(array1[i] - array2[i]);
		/* printf(" i: %.3d   x: %.3f   artanh1: %.10f   artanh2: %.10f\n", i, x, array1[i], array2[i]); */
	}
	/* Calculate the accuracy as the mean absolute deviation (MAD) of the two methods */
	acc = sumdiffs / (n+1);
	printf(" Accuracy: %.10g\n", acc);	

}

double artanh1(double x, double delta){
	/* Calculate artanh(x) using the Maclaurin series and a precision variable delta (lower is more accurate) */
	double el, n, sum;
	n = 0;
	sum = 0;
	el = delta + 1;		/* initialize to force first run through of while loop */
	while (fabs(el) > delta) { /* stop if the absolute value of the added element is smaller or equal delta */
		el = pow(x, 2*n+1)/(2*n+1);	/* Maclaurin series */
		sum = sum + el;
		n = n + 1;
	}

	return sum;
}

double artanh2(double x){
	/* Calculate artanh(x) using natural logarithms with inbuilt approximations */
	return 0.5 * (log(1+x) - log(1-x));
}


