#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.maximumSwap(2736), 7236);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.maximumSwap(9973), 9973);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.maximumSwap(1234), 4231);
}
