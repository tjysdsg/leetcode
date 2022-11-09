// https://leetcode.cn/problems/add-two-numbers/

#pragma once

#include "common.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0), *curr = ret;
        int flag = 0;
        while (l1 || l2) {
            int v1 = 0, v2 = 0;
            if (l1) v1 = l1->val;
            if (l2) v2 = l2->val;

            int num = flag + v1 + v2;
            if (num >= 10) {
                flag = 1;
                num %= 10;
            } else {
                flag = 0;
            }

            assert(curr);
            curr->val = num;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if (l1 || l2) {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }

        if (flag)
            curr->next = new ListNode(1);
        return ret;
    }
};
