// https://leetcode.cn/problems/merge-two-sorted-lists/

#pragma once

#include "common.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode fake(-1);
        ListNode *head = &fake;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }

            head = head->next;
        }

        if (list1) {
            head->next = list1;
        } else if (list2) {
            head->next = list2;
        }

        return fake.next;
    }
};
