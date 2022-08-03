#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *list = ListNode::from_array({4, 2, 1, 3});
    auto *res = sol.sortList(list);
    vector<int> ans{1, 2, 3, 4};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *list = ListNode::from_array({-1, 5, 3, 4, 0});
    auto *res = sol.sortList(list);
    vector<int> ans{-1, 0, 3, 4, 5};
    EXPECT_EQ(res->to_array(), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto *res = sol.sortList(nullptr);
    EXPECT_EQ(res, nullptr);
}
