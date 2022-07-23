#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.mySqrt(4), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.mySqrt(8), 2);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.mySqrt(1), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.mySqrt(2147395599), 46339);
}
