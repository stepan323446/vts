#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *p = &a;
    printf("%p", &p);

    return 0;
}