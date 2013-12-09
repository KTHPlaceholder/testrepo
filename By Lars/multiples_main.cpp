#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "multiples.cpp"
using namespace std;

int main(){
	    printf("If we list all the natural numbers below 10(limit) that are multiples of 3 or 5, we get 3, 5, 6 and 9.\nThe sum of these multiples is 23.\nPlease specify your wished limit: ");
        int n;
        scanf("%d",&n);
        int result = multiples(n);
        printf("The sum of all natural numbers under %d that are multiples of 3 or 5 is: %d \n",n,result);
}
    