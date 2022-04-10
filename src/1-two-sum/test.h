#pragma once
#include "1-two-sum.hpp"
#include <gtest/gtest.h>
#include <algorithm>
SOLUTION_CLASS sol;

TEST(two_sum, 1) {
  vector<int> nums{2, 7, 11, 15};
  auto res = sol.twoSum(nums, 9);
  std::sort(res.begin(), res.end());
  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 1);
}

TEST(two_sum, 2) {
  vector<int> nums{3, 2, 4};
  auto res = sol.twoSum(nums, 6);
  std::sort(res.begin(), res.end());
  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 2);
}

TEST(two_sum, 3) {
  vector<int> nums{3, 3};
  auto res = sol.twoSum(nums, 6);
  std::sort(res.begin(), res.end());
  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 1);
}

TEST(two_sum, 4) {
  vector<int> nums{3, 2, 95, 4, -3};
  auto res = sol.twoSum(nums, 92);
  std::sort(res.begin(), res.end());
  EXPECT_EQ(res[0], 2);
  EXPECT_EQ(res[1], 4);
}
