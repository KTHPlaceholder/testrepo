#include <cstdio>
#include <iostream>
#include "IntegerToBinary.cpp"

int main(){
  long num;
  printf("Enter positive integer: ");
  scanf("%ld", &num);
  std::cout << IntegerToBinary(num);
  return 0;
}
