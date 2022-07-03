#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(test, 1) {
    SOLUTION_CLASS sol;

    vector<ListNode *> v;

    {
        ListNode *l = new ListNode(5);
        l = new ListNode(4, l);
        l = new ListNode(1, l);
        v.push_back(l);
    }
    {
        ListNode *l = new ListNode(4);
        l = new ListNode(3, l);
        l = new ListNode(1, l);
        v.push_back(l);
    }
    {
        ListNode *l = new ListNode(6);
        l = new ListNode(2, l);
        v.push_back(l);
    }

    ListNode *res = sol.mergeKLists(v);
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 1);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 2);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 3);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 4);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 4);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 5);
    res = res->next;
    EXPECT_TRUE(res);
    EXPECT_EQ(res->val, 6);

    EXPECT_FALSE(res->next);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<ListNode *> v;
    EXPECT_EQ(sol.mergeKLists(v), nullptr);
}
