#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    int b;
    printf("a=");
    scanf("%d", &a);

    printf("b=");
    scanf("%d", &b);

    if(a % b == 0)
        printf("Broj %d deljiv sa %d", a, b);
    else
        printf("Broj %d nije deljiv sa %d", a, b);

    return 0;
}