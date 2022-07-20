#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 5) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 3, 4, 5, 6, 7, 8, 9, 1};
    EXPECT_EQ(sol.search(v, 9), 7);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(sol.search(v, 0), 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(sol.search(v, 3), -1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    EXPECT_EQ(sol.search(v, 0), -1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3};
    EXPECT_EQ(sol.search(v, 2), -1);
}
