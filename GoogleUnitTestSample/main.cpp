
#include <gtest/gtest.h>

double squareroot (double num) {
    return num * num;
}

TEST (SquareRootTest, ZeroAndNegativeNos) {
    ASSERT_EQ (0.0, squareroot (0.0));
    }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
