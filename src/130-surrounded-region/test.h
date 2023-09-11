#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
    vector<vector<char>> ans{{'X', 'X', 'X', 'X'},
                             {'X', 'X', 'X', 'X'},
                             {'X', 'X', 'X', 'X'},
                             {'X', 'O', 'X', 'X'}};
    sol.solve(board);
    EXPECT_EQ(board, ans);
}
