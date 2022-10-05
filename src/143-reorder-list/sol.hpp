// https://leetcode.cn/problems/reorder-list/

#pragma once

#include "common.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head->next || !head->next->next) return;

        // find middle of the list
        ListNode *mid = head; // slow pointer
        ListNode *fast = head; // fast pointer
        ListNode *end = head;
        while (fast && fast->next) {
            end = fast->next;
            if (end->next)
                end = end->next;

            mid = mid->next;
            fast = fast->next->next;
        }
        assert(end);

        // reverse the second half
        ListNode *prev = nullptr;
        ListNode *curr = mid->next;
        ListNode *tmp = nullptr;
        mid->next = nullptr; // cut off list at the middle point

        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge two lists
        ListNode fake;
        curr = &fake;
        while (head && end) {
            curr->next = head;
            head = head->next;

            curr = curr->next;

            curr->next = end;
            end = end->next;

            curr = curr->next;
        }
        if (head)
            curr->next = head;
        if (end)
            curr->next = end;
    }
};
