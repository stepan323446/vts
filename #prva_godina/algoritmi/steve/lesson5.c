#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100] = {0};
    int x, poz, n=10;

    // Input
    for(int i = 0; i < n; i++) {
        arr[i] = 4*i-1;
    }

    // Output
    for(int i = 0; i < n; i++) {
        printf("%d |", arr[i]);
    }

    // Pomerujemo novi broj u drugo mesto
    printf("\nKoji broj ubacijemo: ");
    scanf("%d", &x);

    printf("\nNa koje mesto: ");
    scanf("%d", &poz);

    for(int i=++n-1; i >= poz; i--) {
        arr[i] = arr[i-1];
    }
    arr[poz - 1] = x;

    // Output
    for(int i = 0; i < n; i++) {
        printf("%d |", arr[i]);
    }

    return 0;
}