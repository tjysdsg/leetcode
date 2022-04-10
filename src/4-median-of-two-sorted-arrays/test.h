#pragma once
#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>
SOLUTION_CLASS sol;

TEST(median_of_two_sorted_arrays, 1) {
  vector<int> nums1{1, 3};
  vector<int> nums2{2};
  double res = sol.findMedianSortedArrays(nums1, nums2);
  EXPECT_DOUBLE_EQ(res, 2);
}

TEST(median_of_two_sorted_arrays, 2) {
  vector<int> nums1{1, 2};
  vector<int> nums2{3, 4};
  double res = sol.findMedianSortedArrays(nums1, nums2);
  EXPECT_DOUBLE_EQ(res, 2.5);
}

TEST(median_of_two_sorted_arrays, 3) {
  vector<int> nums1{};
  vector<int> nums2{1};
  double res = sol.findMedianSortedArrays(nums1, nums2);
  EXPECT_DOUBLE_EQ(res, 1);
}
