#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float zadatak1(int);
void printTrougao(int);
int random20to30();
void zadatak4();
int randRange(int min, int max);

int main() {
    srand(time(0));


    int n;
    printf("Enter num: ");
    scanf("%d", &n);
    // printf("Result: %.2f\n", zadatak1(n));
    printTrougao(n);
    printf("Random number from 20 to 30: %d\n\n", random20to30());
    zadatak4();

    return 0;
}
int factorial(int n) {
    // U početku uvek 1 * ...
    int res = 1;

    // Factorial: 1 * 1 * 2 * 3 * 4 * ... * n 
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
// Простое число или нет
int isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

float zadatak1(int n) {
    int is_positive = 1;
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        if(is_positive)
            sum += 1.0/factorial(i);
        else
            sum -= 1.0/factorial(i);

        printf("%c 1 / %d\n", (is_positive) ? '+' : '-', factorial(i));

        is_positive = !is_positive;
    }
    return sum;
}
void printTrougao(int n) {
    for(int i = n; i > 0; i--) {
        for (int space = 0; space < n - i; space++) {
            printf(" ");
        }
        for (int leftI = 0; leftI < i - 1; leftI++) {
            printf("%d", i);
        }
        printf("%d", i);
        for (int rightI = 0; rightI < i - 1; rightI++) {
            printf("%d", i);
        }

        printf("\n");
    }
}
int random20to30() {
    return randRange(20, 30);
}

void zadatak4() {
    const int dimension = 8;
    int matrica[dimension][dimension];
    for(int red = 0; red < dimension; red++) {
        for(int col = 0; col < dimension; col++) {
            matrica[red][col] = random20to30();
            printf("%d ", matrica[red][col]);
        }
        printf("\n");
    }

    // Iznad glanve diagonale
    printf("\nIznad glavne diagonale: ");
    for(int red = 0; red < dimension; red++) {
        for(int col = 0; col < dimension; col++) {
            if(col <= red)
                continue;

            printf("%d ", matrica[red][col]);
        }
    }
    printf("\n");

    // Prosti brijeva po diagonale
    printf("\nProsti brojeva na diagonale: ");
    for(int i = 0; i < dimension; i++) {
        if(isPrime(matrica[i][i]))
            printf("%d ", matrica[i][i]);
    }
}