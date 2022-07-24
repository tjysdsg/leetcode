#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *node = new ListNode(
            1,
            new ListNode(
                    2,
                    new ListNode(
                            3,
                            new ListNode(
                                    4,
                                    new ListNode(5)
                            )
                    )
            )
    );
    auto *res = sol.removeNthFromEnd(node, 2);
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_EQ(res->val, 2);
    res = res->next;
    EXPECT_EQ(res->val, 3);
    res = res->next;
    EXPECT_EQ(res->val, 5);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *res = sol.removeNthFromEnd(new ListNode(1), 1);
    EXPECT_EQ(res, nullptr);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto *node = new ListNode(
            1,
            new ListNode(2)
    );
    auto *res = sol.removeNthFromEnd(node, 1);
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_EQ(res, nullptr);
}
