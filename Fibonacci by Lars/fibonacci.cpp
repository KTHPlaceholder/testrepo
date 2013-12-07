#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main()
{
        printf("This is a boring program calculating the nth Fibonacci number.\nPlease enter which Fibonacci you want:");
        int n;
        scanf("%d",&n);
        if(n == 1 || n == 0){
                printf("The Fibonacci number %d is: %d\n",1,1);
        }else{
                int fiba = 0;
                int fibb = 1;
                int fib = 0;
                for(int i = 2; i <= n; i++){
                        fib = fiba + fibb;
                        fiba = fibb;
                        fibb = fib;
                }
                printf("The Fibonacci number %d is: %d \n",n,fib);
        }

        return 0;
}