#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<string>> ans{
            {".Q..", "...Q", "Q...", "..Q."},
            {"..Q.", "Q...", "...Q", ".Q.."}
    };
    EXPECT_EQ(sol.solveNQueens(4), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<string>> ans{{"Q"}};
    EXPECT_EQ(sol.solveNQueens(1), ans);
}
