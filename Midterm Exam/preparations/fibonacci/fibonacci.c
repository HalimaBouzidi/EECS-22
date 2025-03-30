#include <stdio.h>
#include "fibonacci.h"

void GenerateFibonacci(int n)
{
    int a = 0, b = 1, c;
    printf("Fibonacci sequence up to %d: ", n);
    while (a <= n)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}