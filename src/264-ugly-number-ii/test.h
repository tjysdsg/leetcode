#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(ugly_number_ii, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nthUglyNumber(10), 12);
}

TEST(ugly_number_ii, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nthUglyNumber(1), 1);
}

TEST(ugly_number_ii, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nthUglyNumber(260), 46656);
}

TEST(ugly_number_ii, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nthUglyNumber(1690), 2123366400);
}
