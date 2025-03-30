#include <stdio.h>
#include "fibonacci.h"

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    GenerateFibonacci(n);

    return 0;
}