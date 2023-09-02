#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 0, 6, 1, 5};
    EXPECT_EQ(sol.hIndex(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3, 1};
    EXPECT_EQ(sol.hIndex(v), 1);
}
