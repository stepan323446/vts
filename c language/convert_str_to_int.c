#include <stdio.h>
#include <stdlib.h>

int main() {
    char num_str[5];
    printf("Enter one number: ");
    scanf("%s", &num_str);
    printf("%c\n", num_str[2]);
    int i = 0;
    while (num_str[i] != '\0') {
        printf("%d\n", (int)num_str[i]);
        i++;
    }
    
    

    return 0;
}