#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *l1 = ListNode::from_array({1, 2, 4});
    auto *l2 = ListNode::from_array({1, 3, 4});
    auto *res = sol.mergeTwoLists(l1, l2);
    vector<int> ans{1, 1, 2, 3, 4, 4};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *l1 = ListNode::from_array({});
    auto *l2 = ListNode::from_array({});
    auto *res = sol.mergeTwoLists(l1, l2);
    vector<int> ans{};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto *l1 = ListNode::from_array({});
    auto *l2 = ListNode::from_array({0});
    auto *res = sol.mergeTwoLists(l1, l2);
    vector<int> ans{0};
    EXPECT_EQ(res->to_array(), ans);
}
