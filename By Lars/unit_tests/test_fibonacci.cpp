//
//  test_fibonacci.cpp
//
//
//  Created by Hiro on 2013-12-08.
//
//

#include "gtest/gtest.h"
#include "../fibonacci.h"

namespace {
  
  class FibonacciTest : public ::testing::Test {
  protected:
    FibonacciTest() {
      // You can do set-up work for each test here.
    }
    
    virtual ~FibonacciTest() {
      // You can do clean-up work that doesn't throw exceptions here.
    }
    
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    
    virtual void SetUp() {
      // Code here will be called immediately after the constructor (right
      // before each test).
    }
    
    virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }
    
    // Objects declared here can be used by all tests in the test case for Euklid.
  };
  
  TEST_F(FibonacciTest, EdgeCases) {
    EXPECT_EQ("The Fibonacci number 0 is: 0\n", fibonacci(0));
    EXPECT_EQ("The Fibonacci number 1 is: 1\n", fibonacci(1));
    EXPECT_EQ("The Fibonacci number 2 is: 1 \n", fibonacci(2));
  }
  
  TEST_F(FibonacciTest, SimpleCases) {
    EXPECT_EQ("The Fibonacci number 10 is: 55 \n", fibonacci(10));
    EXPECT_EQ("The Fibonacci number 20 is: 6765 \n", fibonacci(20));  }
  
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}