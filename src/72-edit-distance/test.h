#pragma once
#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>
SOLUTION_CLASS sol;

TEST(edit_distance, 1) {
  int d = sol.minDistance("horse", "ros");
  EXPECT_DOUBLE_EQ(d, 3);
}

TEST(edit_distance, 2) {
  int d = sol.minDistance("intention", "execution");
  EXPECT_DOUBLE_EQ(d, 5);
}
