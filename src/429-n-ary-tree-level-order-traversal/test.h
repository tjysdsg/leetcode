#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    Node *tree = new Node(1, {
            new Node(3, {new Node(5), new Node(6)}),
            new Node(2),
            new Node(4),
    });
    vector<vector<int>> ans{
            {1},
            {3, 2, 4},
            {5, 6},
    };
    EXPECT_EQ(sol.levelOrder(tree), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    vector<vector<int>> ans{};
    EXPECT_EQ(sol.levelOrder(nullptr), ans);
}
