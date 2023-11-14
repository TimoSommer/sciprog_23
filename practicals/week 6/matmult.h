#include <stdio.h>
#include <math.h>

void multiply_matrices(void) {
    // This function multiplies the matrices specified in the task and prints them.

    /* Declare variables */
    int i, k, l, n, p, q;
    n = 5;
    p = 3;
    q = 4;
    double A[n][p], B[p][q], C[n][q], sum;

    // Initialize C with zeros
    for (i=0; i<n; i++){
        for (k=0; k<q; k++){
            C[i][k] = 0;
        }
    }
    // Initialize A
    for (i=0; i<n; i++){
        for (k=0; k<p; k++){
            A[i][k] = i + k;
        }
    }
    // Initialize B
    for (i=0; i<p; i++){
        for (k=0; k<q; k++){
            B[i][k] = i - k;
        }
    }

    // Matrix Multiplication A*B=C
    for (i=0; i<n; i++){
        for (k=0; k<q; k++){
            sum = 0;
            for (l=0; l<p; l++){
                sum += A[i][l]*B[l][k];
            }
            C[i][k] = sum;
        }
    }


    // Print matrices
    printf("Matrix A:\n");
    for (i=0; i<n; i++){
        for (k=0; k<p; k++){
            printf("%.0f   ", A[i][k]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (i=0; i<p; i++){
        for (k=0; k<q; k++){
            printf("%.0f   ", B[i][k]);
        }
        printf("\n");
    }
    printf("Matrix C=A*B:\n");
    for (i=0; i<n; i++){
        for (k=0; k<q; k++){
            printf("%.0f   ", C[i][k]);
        }
        printf("\n");
    }
}

