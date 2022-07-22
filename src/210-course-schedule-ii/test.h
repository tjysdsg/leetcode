#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector <vector<int>> v{
            {1, 0},
    };
    vector<int> ans{0, 1};
    EXPECT_EQ(sol.findOrder(2, v), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2},
    };
    vector<vector<int>> answers{
            {0, 2, 1, 3},
            {0, 1, 2, 3},
    };

    EXPECT_THAT(answers, Contains(sol.findOrder(4, v)));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector <vector<int>> v{
            {1, 0},
            {2, 0},
            {0, 2},
    };
    vector<int> ans{};
    EXPECT_EQ(sol.findOrder(3, v), ans);
}
