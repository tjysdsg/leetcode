#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    sol.push(1);
    sol.push(2);
    EXPECT_EQ(sol.peek(), 1);
    EXPECT_EQ(sol.pop(), 1);
    EXPECT_EQ(sol.empty(), false);
    EXPECT_EQ(sol.pop(), 2);
    EXPECT_EQ(sol.empty(), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    sol.push(1);
    sol.push(8);
    EXPECT_EQ(sol.pop(), 1);
    sol.push(3);
    EXPECT_EQ(sol.peek(), 8);
    EXPECT_EQ(sol.pop(), 8);
    sol.push(5);
    EXPECT_EQ(sol.pop(), 3);
}
