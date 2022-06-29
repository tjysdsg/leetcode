#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(kth_largest, 1) {
    SOLUTION_CLASS sol;
    vector<int> nums{3, 2, 1, 5, 6, 4};
    EXPECT_EQ(sol.findKthLargest(nums, 2), 5);
}

TEST(kth_largest, 2) {
    SOLUTION_CLASS sol;
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    EXPECT_EQ(sol.findKthLargest(nums, 4), 4);
}
