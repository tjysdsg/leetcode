#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 0},
                          {1, 2},
                          {1, 3}};
    vector<int> ans{1};
    EXPECT_THAT(sol.findMinHeightTrees(4, v), UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{3, 0},
                          {3, 1},
                          {3, 2},
                          {3, 4},
                          {5, 4}};
    vector<int> ans{3, 4};
    EXPECT_THAT(sol.findMinHeightTrees(6, v), UnorderedElementsAreArray(ans));
}
