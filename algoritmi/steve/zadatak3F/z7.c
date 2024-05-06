/*
7.	Korisnik treba da zada interval brojeva koji se posmatra i u datom intervalu treba naći sve one proste brojeve p za koje važi da su p, p+2, p+6 i p+8 takođe prosti brojevi. 

Na primer, p=3 je prost broj, ali p+6 nije, tako da ne zadovoljava postavljeni uslov. Prost broj p=5 zadovoljava postavljene uslove jer je i p+2, p+6 i p+8 prost broj.

*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main() {
    int from;
    int to;
    printf("Start number: ");
    scanf("%d", &from);
    printf("End number: ");
    scanf("%d", &to);
    
    for(int number = from; number <= to; number ++) {
        if(isPrime(number) && isPrime(number + 2) && isPrime(number + 6) && isPrime(number + 8)) {
            printf("%d\n", number);
        }
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