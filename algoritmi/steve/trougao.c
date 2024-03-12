#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int size;
    printf("Enter size trougao: ");
    scanf("%d", &size);
    printf("\n========\n");


    
    for(int lineWidth = size; lineWidth > 0; lineWidth--) {
        // Place empty width
        printf("%*s", lineWidth - 1, "");

        // Trougao with
        for(int width = 1; width <= (size - lineWidth + 1); width++) {
            printf("%*c", 2, '*');
        }
        // New line
        printf("\n");
    }
    /*
    Za više informacije šta je *:
    https://www.quora.com/In-the-printf-statement-what-is-the-meaning-of-an-asterisk-before-the-s-format-specifier
    */
}