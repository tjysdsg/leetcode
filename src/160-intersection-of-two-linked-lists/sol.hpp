// https://leetcode.cn/problems/intersection-of-two-linked-lists/

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

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int len_a = 0;
        int len_b = 0;

        ListNode *tmp_a = a;
        ListNode *tmp_b = b;
        while (tmp_a) {
            ++len_a;
            tmp_a = tmp_a->next;
        }
        while (tmp_b) {
            ++len_b;
            tmp_b = tmp_b->next;
        }

        int diff = std::abs(len_a - len_b);
        if (len_a > len_b) {
            for (int i = 0; i < diff; ++i)
                a = a->next;
        } else {
            for (int i = 0; i < diff; ++i)
                b = b->next;
        }

        while (a != b) {
            a = a->next;
            b = b->next;
        }

        return a;
    }
};
