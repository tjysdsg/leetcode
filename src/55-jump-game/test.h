#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 3, 1, 1, 4};
    EXPECT_EQ(sol.canJump(v), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 2, 1, 0, 4};
    EXPECT_EQ(sol.canJump(v), false);
}
