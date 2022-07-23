#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    sol.push(-2);
    sol.push(0);
    sol.push(-3);
    EXPECT_EQ(sol.getMin(), -3);
    sol.pop();
    EXPECT_EQ(sol.top(), 0);
    EXPECT_EQ(sol.getMin(), -2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    sol.push(2147483646);
    sol.push(2147483646);
    sol.push(2147483647);
    EXPECT_EQ(sol.top(), 2147483647);
    sol.pop();
    EXPECT_EQ(sol.getMin(), 2147483646);
    sol.pop();
    EXPECT_EQ(sol.getMin(), 2147483646);
    sol.pop();
    sol.push(2147483647);
    EXPECT_EQ(sol.top(), 2147483647);
    sol.push(-2147483648);
    EXPECT_EQ(sol.top(), -2147483648);
    EXPECT_EQ(sol.getMin(), -2147483648);
    sol.pop();
    EXPECT_EQ(sol.getMin(), 2147483647);
}
