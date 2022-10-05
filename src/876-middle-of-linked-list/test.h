#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1, 2, 3, 4, 5});
    EXPECT_EQ(sol.middleNode(n)->val, 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(sol.middleNode(n)->val, 4);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1});
    EXPECT_EQ(sol.middleNode(n)->val, 1);
}
