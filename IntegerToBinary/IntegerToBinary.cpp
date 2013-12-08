//
//  Program converting positive integers to 32 bit binary representations.
//
//  Created by Hiro on 2013-12-07.
//  Copyright (c) 2013 Hiro. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <string>

std::string IntegerToBinary(int a) {
  int bitwise_right_shifted;
  std::string result;
  
  if(a > INT_MAX) {
    result.append("Integer is larger than 32 bit.");
  } else if(a < 0) {
    result.append("Integer is negative.");
  } else {
    result.append("Binary representation (32 bit): ");
    // Since user input is an integer, cast long to int.
    int num_int = (int) a;
    
    for(int i = 31; i >= 0; i--) {
      // Bitwise right shift.
      bitwise_right_shifted = num_int >> i;
      // Bitwise AND.
      if(bitwise_right_shifted & 1) {
        result.append("1");
      } else {
        result.append("0");
      }
    }
  }
  return result;
}

