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
    EXPECT_EQ(sol.top(), 2);
    EXPECT_EQ(sol.pop(), 2);
    EXPECT_EQ(sol.empty(), false);
}
