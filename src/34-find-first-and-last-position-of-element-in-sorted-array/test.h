#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 5) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 2};
    vector<int> ans{0, 1};
    EXPECT_EQ(sol.searchRange(v, 2), ans);
}


TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{5, 8, 8, 8, 8, 10};
    vector<int> ans{1, 4};
    EXPECT_EQ(sol.searchRange(v, 8), ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{5, 7, 7, 8, 8, 10};
    vector<int> ans{3, 4};
    EXPECT_EQ(sol.searchRange(v, 8), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{5, 7, 7, 8, 8, 10};
    vector<int> ans{-1, -1};
    EXPECT_EQ(sol.searchRange(v, 6), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{};
    vector<int> ans{-1, -1};
    EXPECT_EQ(sol.searchRange(v, 0), ans);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    vector<int> ans{0, 0};
    EXPECT_EQ(sol.searchRange(v, 1), ans);
}

