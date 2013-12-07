#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main()
{
        printf("If we list all the natural numbers below 10(limit) that are multiples of 3 or 5, we get 3, 5, 6 and 9.\nThe sum of these multiples is 23.\nPlease specify your wished limit: ");
        int n;
        scanf("%d",&n);
        if(n < 3){
                printf("The sum of all natural numbers under %d that are multiples of 3 or 5 is: %d \n",n,0);
        }else if(n < 5){
                printf("The sum of all natural numbers under %d that are multiples of 3 or 5 is: %d \n",n,3);
        }else{
                int a = 3;
                int b = 5;
                int sum = 0;
                for(int i = 1; i < n;i++){
                        if(i % 3 == 0 || i % 5 == 0){
                                sum += i;
                        }        
                }
                printf("The sum of all natural numbers under %d that are multiples of 3 or 5 is: %d \n",n,sum);
        }

        return 0;
}