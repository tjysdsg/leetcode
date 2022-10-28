#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3};
    vector<vector<int>> ans{{1, 2, 3},
                            {1, 3, 2},
                            {2, 1, 3},
                            {2, 3, 1},
                            {3, 1, 2},
                            {3, 2, 1}};
    EXPECT_THAT(sol.permute(v), UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 1};
    vector<vector<int>> ans{{0, 1},
                            {1, 0}};
    EXPECT_THAT(sol.permute(v), UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    vector<vector<int>> ans{{1}};
    EXPECT_EQ(sol.permute(v), ans);
}
