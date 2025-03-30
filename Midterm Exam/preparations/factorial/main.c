#include <stdio.h>
#include "factorial.h"

int main(void)
{
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    unsigned long long result = Factorial(n);
    if (result == -1)
        printf("Error: Negative input.\n");
    else
        printf("Factorial of %d is %llu\n", n, result);

    return 0;
}