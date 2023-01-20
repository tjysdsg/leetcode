#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    auto *node = ListNode::from_array({1, 2, 3, 4, 5});
    auto *res = sol.reverseBetween(node, 2, 4);

    vector<int> ans{1, 4, 3, 2, 5};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    auto *node = ListNode::from_array({1, 2, 3, 4});
    auto *res = sol.reverseBetween(node, 2, 4);

    vector<int> ans{1, 4, 3, 2};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;

    auto *node = ListNode::from_array({1, 2, 3, 4});
    auto *res = sol.reverseBetween(node, 1, 4);

    vector<int> ans{4, 3, 2, 1};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;

    auto *node = ListNode::from_array({1, 2, 3, 4});
    auto *res = sol.reverseBetween(node, 2, 2);

    vector<int> ans{1, 2, 3, 4};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 5) {
    SOLUTION_CLASS sol;

    auto *node = ListNode::from_array({3, 5});
    auto *res = sol.reverseBetween(node, 1, 2);

    vector<int> ans{5, 3};
    EXPECT_EQ(res->to_array(), ans);
}
