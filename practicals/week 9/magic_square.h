#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int ** square, const int n) {

    int M, i, j, row_sum, col_sum, main_diag_sum, sec_diag_sum;

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    M = (n * (n*n + 1))/2;

    // Checking that every row and column add up to M
    for (i = 0; i < n; i++) {
        row_sum = 0;
        col_sum = 0;

        // Summing rows and columns at the same time by switching the order of indices
        for (j = 0; j < n; j++) {
            row_sum += square[i][j];
            col_sum += square[j][i];
        }

        // If row or column sum is not M, it is not a magic square
        if (row_sum != M || col_sum != M) {
            return 0;
        }
    }

    // Checking that the main and secondary
    // diagonals each add up to M
    // If passed all checks, it is a magic square
    main_diag_sum = 0;
    sec_diag_sum = 0;
    for (i = 0; i < n; i++) {
        // Sum up both diagonals
        main_diag_sum += square[i][i];
        sec_diag_sum += square[i][n-i-1];
    }
    // If row or column sum is not M, it is not a magic square
    if (main_diag_sum != M || sec_diag_sum != M) {
        return 0;
    }


    // If we get here, all checks passed and it is a magic square
    return 1;
}

