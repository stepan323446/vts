#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100

void generateArray(int, int, int arr[], int);
void displayArray(int arr[], int);
double medianArray(int arr[], int);
void bubbleSort(int arr[], int, int);

int main() {
    int min, max, n;
    int array[MAX];
    printf("Write min number: ");
    scanf("%d", &min);

    printf("Write max number: ");
    scanf("%d", &max);

    printf("Write n number: ");
    scanf("%d", &n);

    generateArray(min, max, array, n);
    
    printf("Median array is %.2f\n", medianArray(array, n));
    displayArray(array, n);

    return 0;
}
void generateArray(int min, int max, int arr[], int n) {
    printf("Array with random numbers from %d to %d\n", min, max);

    srand(time(0));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n, int isAcsending) {
    int temp;
    int isReady;

    do {
        isReady = 1;
        for(int i = 0; i < n; i++) {
            // Last index
            if(i == n - 1)
                continue;

            if(arr[i] > arr[i + 1] && isAcsending == 1) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
            else if (arr[i] < arr[i + 1] && isAcsending == 0) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
        }
    }
    while(!isReady);
}
int countElemsArray(int arr[], int n, int item) {
    
}
double medianArray(int arr[], int n) {
    bubbleSort(arr, n, 1);

    if(n % 2 == 0) {
        return arr[n / 2] + arr[n / 2 - 1] / 2.0;
    }
    else {
        return (double)arr[n/2];
    }
}
void displayArray(int arr[], int n) {
    printf("Display array: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d]: %d\n", i, arr[i]);
    }
    printf("END\n\n"); 
}