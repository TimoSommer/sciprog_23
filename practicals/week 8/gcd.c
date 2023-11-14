#include <stdio.h>

// Declare functions
int get_gcd_iter(int a, int b);
int get_gcd_recurs(int a, int b);

int main(void) {
    // Declare variables
    int a, b;
    a = 8;
    b = 12;

    // Calculate GCD in both iterative and recursive way.
    printf("GCD of a=%d and b=%d:\n", a, b);
    get_gcd_iter(a, b);
    get_gcd_recurs(a, b);

    return 0;
}

int get_gcd_iter(int a, int b){
    // Returns the Greatest Common Divisor (GCD) of a and b, calculated in an iterative way.
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("Iter GCD: %d\n", a);
    return a;
}
int get_gcd_recurs(int a, int b){
    // Returns the Greatest Common Divisor (GCD) of a and b, calculated in a recursive way.
    if (b == 0){
        printf("Recurs GCD: %d\n", a);
        return a;
    } else {
        int newb;
        newb = a % b;
        get_gcd_recurs(b, newb);
    }

    return 999;
}