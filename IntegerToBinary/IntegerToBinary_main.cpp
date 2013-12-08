#include <cstdio>
#include "IntegerToBinary.h"

int main(){
  long num;
  printf("Enter positive integer: ");
  scanf("%ld", &num);
  printf(IntegerToBinary(num));
  return 0;
}