#include <stdio.h>
#include <stdlib.h>

int getDecimalCounts(int num) {
    int res = 0;
    int otherDecimalResults = 0;

    int checkDecimal = num / 10;
    if(checkDecimal > 0)
        res++;

    if(checkDecimal > 9) {
        otherDecimalResults = getDecimalCounts(checkDecimal);
    }
    res = res + otherDecimalResults;

    return res;
}

int main()
{
    int num = 5;
    printf("%d", getDecimalCounts(num));

    return 0;
}