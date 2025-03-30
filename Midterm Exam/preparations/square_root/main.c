/* main.c: Main program file*/

#include <stdio.h>
#include "sqrt.h"

int main(void)
{
    double n, s;

    do
    {
        printf("Enter a real positive number N: ");
        scanf("%lf", &n);
    } while (n < 0.0);

    s = SquareRoot(n);

    printf("The square root of %g is %g\n", n, s);
    
}