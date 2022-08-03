// https://leetcode.cn/problems/sort-list/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;

        ListNode *curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }

        ListNode fake(0, head);
        for (int len = 1; len < n; len *= 2) {
            ListNode *prev = &fake;
            curr = fake.next;

            while (curr) {
                ListNode *l1 = curr;

                // find the end of the first list
                for (int i = 0; i < len - 1; ++i) {
                    if (!curr->next) break;
                    curr = curr->next;
                }
                ListNode *l2 = curr->next; // l2 could be nullptr but that's ok
                curr->next = nullptr;
                curr = l2;

                // find the end of the second list
                for (int i = 0; i < len - 1; ++i) {
                    if (!curr || !curr->next) break;
                    curr = curr->next;
                }
                if (curr) {
                    ListNode *l3 = curr->next;
                    curr->next = nullptr;
                    curr = l3;
                } // otherwise curr and l3 are nullptr

                prev->next = merge(l1, l2);

                // prev = the end of the merged list
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }

        return fake.next;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode fake;
        ListNode *prev = &fake;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        if (l1) prev->next = l1;
        if (l2) prev->next = l2;

        return fake.next;
    }
};
