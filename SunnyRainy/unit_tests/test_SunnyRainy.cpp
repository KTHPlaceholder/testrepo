
#include "gtest/gtest.h"
#include "../is_it_going_to_rain.h"

namespace {

class SunnyRainyTest : public ::testing::Test {
 protected:
  SunnyRainyTest() {
    // You can do set-up work for each test here.
  }

  virtual ~SunnyRainyTest() {
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

  // Objects declared here can be used by all tests in the test case for SunnyRainy.
};

// Test if SunnyRainy can predict the weather correctly
TEST_F(SunnyRainyTest, PredictCorrect) {
	EXPECT_EQ(1.0, predict(1, 1));
}
// Test if SunnyRainy can train the markov model with a bitstring
	
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

