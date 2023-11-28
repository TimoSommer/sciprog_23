#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){

    int n, i;

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);


    // ##! n function which gets the number of lines
    n = getlines(filename);

    // Open the file
    f = fopen(filename, "r");

    // Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row
    int **square = (int **) malloc(n * sizeof(int *));


    // Inputting integer data into the matrix;
    for (i = 0; i < n; i++) {
        square[i] = (int *) malloc(n * sizeof(int));
        fscanf(f, "%d %d %d", &square[i][0], &square[i][1], &square[i][2]);
    }

    // Print matrix
    for (i = 0; i < n; i++) {
        printf("%d ", square[i][0]);
        printf("%d ", square[i][1]);
        printf("%d ", square[i][2]);
        printf("\n");
    }

    // Calculate if it is a magic square and print result
    int magic = isMagicSquare(square, n);
    if (magic == 1) {
        printf("Yey, magic square!\n");
    } else {
        printf("Oh, no magic square!\n");
    }

    // Freeing each row separately before freeing the array of pointers
    for (i = 0; i < n; i++) {
        free(square[i]);
    }
    free(square);

    // Close the file
    fclose(f);

    return 0;
}

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
