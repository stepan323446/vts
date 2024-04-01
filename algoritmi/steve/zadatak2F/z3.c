/*
3.	Napisati program koji za unete cele brojeve m i n (1 ≤ m, n ≤ 50) učitava matricu celih brojeva dimenzije m × n. Učitati broj k. Za unetu matricu, formirati i ispisati niz neparnih brojeva elemenata matrice, koji su deljivi sa k.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void setNumberRange(int *, char, int, int);
int randRange(int, int);
void displayArray(int arr[], int);

int main() {
    int arr[MAX][MAX];

    int n, m;

    srand(time(0));

    setNumberRange(&n, 'n', 1, 50);
    setNumberRange(&m, 'm', 1, 50);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = randRange(0, 100);
        }
    }

    int k;
    printf("Enter k number: ");
    scanf("%d", &k);

    int answer[n*m];
    int answerIndex = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // This is odd number?
            if(arr[i][j] % 2 == 0)
                continue;
            // Can number divided by k?
            if(arr[i][j] % k != 0)
                continue;

            answer[answerIndex] = arr[i][j];
            answerIndex++;
        }
    }
    displayArray(answer, answerIndex);
    

    return 0;
}

int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void setNumberRange(int *num, char letter, int min, int max) {
    do {
        printf("Enter %c number (%d <= %c <= %d): ", letter, min, letter, max);
        scanf("%d", num);

        if(*num > max || *num < min)
            printf("Your number is invalid\n", *num);
        else
            break;
    }
    while (1);
}
void displayArray(int arr[], int n) {
    printf("Display array: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d]: %d\n", i, arr[i]);
    }
    printf("END\n\n"); 
}