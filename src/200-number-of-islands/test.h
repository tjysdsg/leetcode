#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<char>> v{
            {'1', '1', '1'},
            {'1', '0', '1'},
            {'1', '1', '1'}
    };
    EXPECT_EQ(sol.numIslands(v), 1);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<char>> v{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };
    EXPECT_EQ(sol.numIslands(v), 1);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<char>> v{
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
    };
    EXPECT_EQ(sol.numIslands(v), 3);
}
