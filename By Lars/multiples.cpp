#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int multiples(int n)
{
        int a = 3;
        int b = 5;
        int sum = 0;
        for(int i = 1; i < n;i++){
                if(i % 3 == 0 || i % 5 == 0){
                        sum += i;
                }        
        }
        return sum;
}