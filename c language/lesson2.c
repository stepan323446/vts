#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    if(number % 5  == 0 && number % 3 == 0)
        printf("Can be divided by 5 and 3");
    else if (number % 5 == 0)
        printf("Devided by 5");
    else if (number % 3 == 0)
        printf("Devided by 3");
    else
        printf("Nothing can be devided by 5 and/or 3");

    return 0;
}