#include "factorial.h"

unsigned long long Factorial(int n)
{
    if (n < 0)
        return -1; // Error case
    if (n == 0 || n == 1)
        return 1;
    return n * Factorial(n - 1);
}