// https://leetcode.cn/problems/swap-nodes-in-pairs/

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

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TODO: recursion

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode fake(0, head);
        ListNode *n1 = head, *n2, *prev = &fake;

        while (n1) {
            n2 = n1->next;
            ListNode *next = nullptr;
            if (n2) {
                next = n2->next;

                n1->next = next;
                n2->next = n1;
                prev->next = n2;

            }
            prev = n1;
            n1 = next;
        }

        return fake.next;
    }
};
