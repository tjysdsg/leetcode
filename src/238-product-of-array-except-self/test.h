#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3, 4};
    vector<int> ans{24, 12, 8, 6};
    EXPECT_EQ(sol.productExceptSelf(v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{-1, 1, 0, -3, 3};
    vector<int> ans{0, 0, 9, 0, 0};
    EXPECT_EQ(sol.productExceptSelf(v), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 4};
    vector<int> ans{4, 2};
    EXPECT_EQ(sol.productExceptSelf(v), ans);
}
