//
//  Program converting positive integers to 32 bit binary representations.
//
//  Created by Hiro on 2013-12-07.
//  Copyright (c) 2013 Hiro. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int main(int argc, const char * argv[]) {
  long num;
  int bitwise_right_shifted;
  
  printf("Enter positive integer: ");
  scanf("%ld", &num);
  
  if(num > INT_MAX) {
    printf("Integer is larger than 32 bit.");
  } else if(num < 0) {
    printf("Integer is negative.");
  } else {
    printf("Binary representation (32 bit): ");
    // Since user input is an integer, cast long to int.
    int num_int = (int) num;
    
    for(int i = 31; i >= 0; i--) {
      // Bitwise right shift.
      bitwise_right_shifted = num_int >> i;
      // Bitwise AND.
      if(bitwise_right_shifted & 1) {
        printf("1");
      } else {
        printf("0");
      }
    }
  }
  return 0;
}