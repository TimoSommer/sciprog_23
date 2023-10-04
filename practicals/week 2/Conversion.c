#include <stdio.h>
#include <math.h>

int main(void) {
	/* Declare variables */
	int i,inum,tmp,numdigits;
	float fnum;
	char binnum[60];
	/* Intialise 4-byte integer */
	inum = 33554431;
	/* Convert to 4-byte float */
	fnum = (float) inum;
	/* Convert to binary number (string)*/
	i = 0; tmp = inum;
	while (tmp > 0) {
		sprintf(&binnum[i],"%1d",tmp%2);
		tmp = tmp/2;
		i++;
	}
	/* Terminate the string */
	binnum[i] = '\0';
	/* Calculate the number of digits in inum in base 2 and print as int */
	numdigits = ceil( logf(inum)/logf(2) );
	printf("The number of digits is %d\n",numdigits);
	printf("inum=%d, fnum=%f, inum in binary=%s\n",
	inum,fnum,binnum);
}

