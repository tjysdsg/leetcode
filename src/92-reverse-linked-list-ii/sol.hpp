// https://leetcode.cn/problems/reverse-linked-list-ii/

#pragma once

#include "common.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        --left;
        --right;

        ListNode fake(0, head);

        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *before_left_node = &fake;
        ListNode *left_node = nullptr;
        bool reversing = false;

        int i = 0;
        while (curr) {
            if (reversing) {
                auto *tmp = curr->next;
                curr->next = prev;
                prev = curr;

                if (i == right) {
                    reversing = false;
                    left_node->next = tmp;

                    if (before_left_node)
                        before_left_node->next = curr;
                }

                curr = tmp;
                ++i;
            } else {
                if (i == left) {
                    reversing = true;
                    left_node = curr;
                } else {
                    before_left_node = curr;
                    curr = curr->next;
                    ++i;
                }
            }
        }

        return fake.next;
    }
};
