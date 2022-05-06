#pragma once
#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>
SOLUTION_CLASS sol;

TEST(three_sum, 1) {
  vector<int> v{-1, 0, 1, 2, -1, -4};
  auto res = sol.threeSum(v);
  vector<int> e0{-1, -1, 2};
  vector<int> e1{-1, 0, 1};
  vector<vector<int>> ans{e0, e1};
  EXPECT_EQ(res, ans);
}

TEST(three_sum, 2) {
  vector<int> v{};
  auto res = sol.threeSum(v);
  EXPECT_TRUE(res.empty());
}

TEST(three_sum, 3) {
  vector<int> v{0};
  auto res = sol.threeSum(v);
  EXPECT_TRUE(res.empty());
}

TEST(three_sum, 4) {
  vector<int> v{1, 2, -2, -1};
  auto res = sol.threeSum(v);
  EXPECT_TRUE(res.empty());
}

TEST(three_sum, 5) {
  vector<int> v{1, -1, -1, 0};
  auto res = sol.threeSum(v);
  vector<int> e0{-1, 0, 1};
  vector<vector<int>> ans{e0};
  EXPECT_EQ(res, ans);
}
