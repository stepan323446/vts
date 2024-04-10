#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100



int binarySearch(int niz[], int low, int high, int x){  //treba znati i korak po korak
    int mid;
    while(low<=high){

        mid=(low+high)/2;
        if(niz[mid]==x)
            return mid;

        if(niz[mid]<x)
        low=mid+1;


        else
        high=mid-1;


    }


    return -1;



}








int main(){


    int niz[]={2,3,8,12,20,40};
    int n=sizeof(niz)/sizeof(niz[0]);

    int key=2;
    int result=binarySearch(niz, 0, n-1, key);
    if(result==-1)
        printf("nema");
    else
        printf("ima %d na poziciji %d", key, result);





return 0;
}