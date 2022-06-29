#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

SOLUTION_CLASS sol;

TEST(reverse_linked_list, 1) {
    ListNode *head = new ListNode(5);
    head = new ListNode(4, head);
    head = new ListNode(3, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);

    ListNode *res = sol.reverseList(head);

    EXPECT_EQ(res->val, 5);
    res = res->next;
    EXPECT_EQ(res->val, 4);
    res = res->next;
    EXPECT_EQ(res->val, 3);
    res = res->next;
    EXPECT_EQ(res->val, 2);
    res = res->next;
    EXPECT_EQ(res->val, 1);
}

TEST(reverse_linked_list, 2) {
    ListNode *res = sol.reverseList(nullptr);
    EXPECT_EQ(res, nullptr);
}
