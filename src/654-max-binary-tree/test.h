#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3};
    // EXPECT_EQ(sol.constructMaximumBinaryTree(v)->to_heap(), ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 2, 1, 6, 0, 5};
    // EXPECT_EQ(sol.constructMaximumBinaryTree(v)->to_heap(), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    vector<int> ans{1, -1, -1};
    EXPECT_EQ(sol.constructMaximumBinaryTree(v)->to_heap(), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 2, 1};
    // EXPECT_EQ(sol.constructMaximumBinaryTree(v)->to_heap(), ans);
}
