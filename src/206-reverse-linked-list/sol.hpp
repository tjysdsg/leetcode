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
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::set;
using std::stack;

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
