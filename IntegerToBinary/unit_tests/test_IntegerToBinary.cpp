
#include "gtest/gtest.h"
#include "../IntegerToBinary.h"
#include <string>
#include <limits.h>

namespace {

class IntegerToBinaryTest : public ::testing::Test {
 protected:
  IntegerToBinaryTest() {
    // You can do set-up work for each test here.
  }

  virtual ~IntegerToBinaryTest() {
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


TEST(IntegerToBinaryTest, Handles1) {
  EXPECT_EQ("Binary representation (32 bit): 00000000000000000000000000000001", IntegerToBinary(1));
  EXPECT_EQ("Binary representation (32 bit): 00000000000000000000011111000100", IntegerToBinary(1988));
  EXPECT_EQ("Binary representation (32 bit): 00000001011111010111100010000001", IntegerToBinary(25000065));
  EXPECT_EQ("Binary representation (32 bit): 00000001001011110011100011110100", IntegerToBinary(19871988));
}


TEST(IntegerToBinaryTest, Handles2) {
  ASSERT_FALSE("Binary representation (32 bit): 00000000000000000000000000000001" == IntegerToBinary(2));
}

TEST(IntegerToBinaryTest, HandlesNegative) {
   EXPECT_EQ("Integer is negative.", IntegerToBinary(-1));
   EXPECT_EQ("Integer is negative.", IntegerToBinary(INT_MIN));
}

TEST(IntegerToBinaryTest, HandlesOverMaxInt) {
   EXPECT_EQ("Binary representation (32 bit): 01111111111111111111111111111111", IntegerToBinary(INT_MAX));
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
