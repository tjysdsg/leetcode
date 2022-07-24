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
                            new ListNode(4)
                    )
            )
    );
    auto *res = sol.swapPairs(node);
    EXPECT_EQ(res->val, 2);
    res = res->next;
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_EQ(res->val, 4);
    res = res->next;
    EXPECT_EQ(res->val, 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto *node = new ListNode(
            1,
            new ListNode(
                    2,
                    new ListNode(3)
            )
    );
    auto *res = sol.swapPairs(node);
    EXPECT_EQ(res->val, 2);
    res = res->next;
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_EQ(res->val, 3);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto *node = new ListNode(1);
    auto *res = sol.swapPairs(node);
    EXPECT_EQ(res->val, 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.swapPairs(nullptr), nullptr);
}
