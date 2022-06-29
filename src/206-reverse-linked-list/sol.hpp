// https://leetcode.cn/problems/reverse-linked-list/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::set;
using std::stack;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        // if (!head || !head->next) return head;

        ListNode *prev = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = prev;

            prev = head;
            head = tmp;
        }

        return prev;
    }
};
