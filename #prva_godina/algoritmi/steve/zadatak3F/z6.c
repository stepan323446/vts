/*
6.	Brojevi oblika f= 2^(2n)+1, gde je n ceo pozitivan broj, nazivaju se Fermaovi brojevi. Pronađite među njima prvih 5 prostih brojeva i ispište ih. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(unsigned long long int num) {
    if(num == 0 || num == 1)
        return 0;
        
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numberLength = 0;
    for(int n = 1; numberLength < 5; n++) {
        unsigned long long int formula = pow(2, 2*n) + 1;
        // printf("Searching... (%llu)\n", formula);
        if(isPrime(formula)) {
            printf("%llu\n", formula);
            numberLength++;
        }
    }

    return 0;
}

