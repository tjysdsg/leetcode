// https://leetcode.cn/problems/merge-k-sorted-lists/

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
#include <unordered_map>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class DivideConquer {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        size_t n = lists.size();
        if (n == 0) return nullptr;
        else if (n == 1) return lists[0];

        return mergeKLists(lists, 0, n - 1);
    }

    // [i, j]
    ListNode *mergeKLists(vector<ListNode *> &lists, int i, int j) {
        if (i == j)
            return lists[i];

        int mid = (i + j) / 2;

        ListNode *l1 = mergeKLists(lists, i, mid);
        ListNode *l2 = mergeKLists(lists, std::min(mid + 1, j), j);
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode fake_head;
        ListNode *curr = &fake_head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }

            curr = curr->next;
        }
        curr->next = p1 ? p1 : p2;

        return fake_head.next;
    }
};
