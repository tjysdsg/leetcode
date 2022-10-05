#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1, 2, 3, 4});
    vector<int> ans{1, 4, 2, 3};
    sol.reorderList(n);
    EXPECT_EQ(n->to_array(), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1, 2, 3, 4, 5});
    vector<int> ans{1, 5, 2, 4, 3};
    sol.reorderList(n);
    EXPECT_EQ(n->to_array(), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1});
    vector<int> ans{1};
    sol.reorderList(n);
    EXPECT_EQ(n->to_array(), ans);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    ListNode *n = ListNode::from_array({1, 2});
    vector<int> ans{1, 2};
    sol.reorderList(n);
    EXPECT_EQ(n->to_array(), ans);
}
