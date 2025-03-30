#include <stdio.h>
#include "prime.h"

int main(void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (IsPrime(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}