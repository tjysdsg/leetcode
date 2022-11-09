#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *l1 = ListNode::from_array({9, 9, 9, 9, 9, 9, 9});
    auto *l2 = ListNode::from_array({9, 9, 9, 9});
    vector<int> ans{8, 9, 9, 9, 0, 0, 0, 1};
    EXPECT_EQ(sol.addTwoNumbers(l1, l2)->to_array(), ans);
}
