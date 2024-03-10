#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 2;
    int a = 2;
    printf("Your number is ");
    scanf("%d", &n);

    double result = 0;
    // 2 = 1 + 1/2 + 1/4 + ...
    for(int i; i <= n; i++) {
        result += pow(2, -i);
    }
    printf("Result is: %lf", result);

    return 0;
}