#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void displayArray(int, int[]);
int getArrayMaxNum(int, int[]);
int getArrayMinNum(int, int[]);
double getArrayAverageNum(int, int[]);
int isDimesionExists(int);

int main() {
    int arr[MAX_SIZE];
    int n;

    // Input dimension with checking
    printf("Dimenzija niza je (max 100):");
    do {
        scanf("%d", &n);

        if(!isDimesionExists(n))
            printf("Your dimension isn't correct. Repeat: ");
    }
    while(!isDimesionExists(n));


    // Input array
    printf("==== Input =====\n");
    for(int i = 0; i < n; i++) {
        printf("Unesi %d:", i);
        scanf("%d", &arr[i]);
    }

    displayArray(n, arr);
    printf("\nMax number: %d", getArrayMaxNum(n, arr));
    printf("\nMin number: %d", getArrayMinNum(n, arr));
    printf("\nAverage number: %.3f", getArrayAverageNum(n, arr));

    // Complete
    printf("\n===== Completed =====\n");
    return 0;
}

/// @brief Check user's input
/// @param n User's dimension which he has entered
/// @return true/false 
int isDimesionExists(int n) {
    if(n > MAX_SIZE || n < 0) {
        return 0;
    }
    return 1;
}

/// @brief Diplay array and stats
/// @param n User's dimension
/// @param arr array which need to display
void displayArray(int n, int arr[]) {
    printf("\n==== Output =====\n");
    printf("Elementi niza:\n");

    for (int i = 0; i < n; i++)
    {        
        printf("| %d |", arr[i]);
    }
}

/// @param n User's dimension
/// @param arr array
/// @return min number from array
int getArrayMinNum(int n, int arr[]) {
    int max;
    for (int i = 0; i < n; i++)
    {
        if(max > arr[i])
            max = arr[i];
    }
    return max;
}

/// @param n User's dimension
/// @param arr array
/// @return max number from array
int getArrayMaxNum(int n, int arr[]) {
    int max;
    for (int i = 0; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
/// @param n User's dimension
/// @param arr array
/// @return average number from array
double getArrayAverageNum(int n, int arr[]) {
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += arr[i];
    }
    result /= n;
    return result;
}