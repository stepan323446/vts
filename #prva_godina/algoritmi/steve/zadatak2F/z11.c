/*
11.	Napisati program koji za uneti broj n (1 ≤ n ≤ 50) učitava kvadratnu matricu celih brojeva dimenzije n × n. Odrediti najveći element iznad glavne dijagonale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setNumberRange(int *, char, int, int);
int randRange(int, int);

int main() {
    srand(time(0));

    int n;
    setNumberRange(&n, 'n', 1, 50);

    int arr[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = randRange(0, 100);
        }
    }

    // Ispod najveći element iznad glavne dijagonale.
    int maxNumber = arr[0][1];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Ako ispod ili to je dijagonala
            if(j <= i)
                continue;;
            
            if(maxNumber < arr[i][j])
                maxNumber = arr[i][j];
        }
    }
    printf("Max number in array on top from diagonal: %d", maxNumber);

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