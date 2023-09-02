#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> board{
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 35, -1, -1, 13, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 15, -1, -1, -1, -1}
    };

    EXPECT_EQ(sol.snakesAndLadders(board), 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    vector<vector<int>> board{{-1, -1},
                              {-1, 3}};
    EXPECT_EQ(sol.snakesAndLadders(board), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> board{{1,  1, -1},
                              {1,  1, 1},
                              {-1, 1, 1}};
    EXPECT_EQ(sol.snakesAndLadders(board), -1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> board{
            {-1, 1,  2,  -1},
            {2,  13, 15, -1},
            {-1, 10, -1, -1},
            {-1, 6,  2,  8}
    };
    EXPECT_EQ(sol.snakesAndLadders(board), 2);
}
