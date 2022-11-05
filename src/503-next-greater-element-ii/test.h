#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 1};
    vector<int> ans{2, -1, 2};
    EXPECT_EQ(sol.nextGreaterElements(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3, 4, 3};
    vector<int> ans{2, 3, 4, -1, 4};
    EXPECT_EQ(sol.nextGreaterElements(v), ans);
}
