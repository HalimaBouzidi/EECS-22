#include <stdio.h>
#include "reverse.h"

int main(void)
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    ReverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}