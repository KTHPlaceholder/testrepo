
#include "gtest/gtest.h"
#include "../euklidesv2.h"

namespace {

class EuklidTest : public ::testing::Test {
 protected:
  EuklidTest() {
    // You can do set-up work for each test here.
  }

  virtual ~EuklidTest() {
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

// Tests that the euklid method handles primes
TEST_F(EuklidTest, MethodHandlesPrimes) {
  EXPECT_EQ(1, euklides(2,5));
}

// Tests that the euklid method handles 
TEST_F(EuklidTest, MethodCorrect) {
  EXPECT_EQ(5, euklides(5,10));
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

