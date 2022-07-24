// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

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

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return head;

        ListNode fake(0, head);

        // |  ...  | prev | remove |  ...  | end |
        //                     ^----- n ------^
        ListNode *prev = &fake;
        ListNode *end = &fake;
        for (int i = 0; i < n; ++i) {
            assert(end);
            end = end->next;
        }

        while (end->next) {
            end = end->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return fake.next;
    }
};

/* Naive

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return head;

        ListNode fake(0, head);
        vector<ListNode *> nodes{&fake};

        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        int i = nodes.size() - n;
        auto *rm = nodes[i];
        auto *prev = nodes[i - 1]; // i is always bigger than 0 because of fake
        prev->next = rm->next;

        return fake.next;
    }
};

*/
