#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
    /* Declare variables */
    int order, i;
    double *array, result ,e, diff;
    e = exp(1.0);
    order = 16;

    array = (double *) malloc(order * sizeof(double));

    // The array variable will store the estimate (the sum) up to that order.
    result = 0.;
    for (i=0; i<order; i++){
        array[i] = result + 1./tgamma(i+1);  // this is (x^i)/i! with x=1, with the gamma function to calculate the factorial
        result = array[i];
        diff = result - e;
        printf("Order: %d\tResult: %5f\tDiff: %2g\n", i, result, diff);
    }
    printf("In my tests, I do not see higher polynomials leading to worse estimates, as intended by the task. The more higher order polynomials are taken into account, the better the estimate becomes, as is expected mathematically. Perhaps the task refers to a numerical issue which doesn't seem to appear in my code.\n");

    return 0;
}


