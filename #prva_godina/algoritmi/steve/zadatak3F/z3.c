/*
3.	Odredite prvih 10 prostih brojeva koji se dobijaju pomoću formule p+14 gde je p takođe prost broj. 
Na primer, p=3 je prost broj, p+14=17 je prost broj koji zadovoljava uslov. p=5 je prost broj, p+14=19 je prost broj koji zadovoljava uslov.
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main() {
    int numLength = 0;
    int p = 0;
    while(1) {
        if(isPrime(p) && isPrime(p + 14)) {
            printf("%d\n", p + 14);
            numLength++;
        }
        if(numLength >= 10)
            break;
        
        p++;
    }
    return 0;
}
int isPrime(int num) {
    if(num == 0 || num == 1)
        return 0;
        
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}