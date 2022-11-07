#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    auto *node = TreeNode::from_heap({7, 3, 15, -1, -1, 9, 20});
    SOLUTION_CLASS sol(node);
    EXPECT_EQ(sol.next(), 3);
    EXPECT_EQ(sol.next(), 7);
    EXPECT_EQ(sol.hasNext(), true);
    EXPECT_EQ(sol.next(), 9);
    EXPECT_EQ(sol.hasNext(), true);
    EXPECT_EQ(sol.next(), 15);
    EXPECT_EQ(sol.hasNext(), true);
    EXPECT_EQ(sol.next(), 20);
    EXPECT_EQ(sol.hasNext(), false);
}
