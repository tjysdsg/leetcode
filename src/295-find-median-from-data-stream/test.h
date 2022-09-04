#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    sol.addNum(1);    // arr = [1]
    sol.addNum(2);    // arr = [1, 2]
    EXPECT_EQ(sol.findMedian(), 1.5); // return 1.5 (i.e., (1 + 2) / 2)
    sol.addNum(3);    // arr[1, 2, 3]
    EXPECT_EQ(sol.findMedian(), 2.0); // return 2.0
}
