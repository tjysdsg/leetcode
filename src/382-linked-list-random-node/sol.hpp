// https://leetcode.cn/problems/linked-list-random-node/

#pragma once

#include "common.h"
#include <random>
#include <limits>

class Solution {
    ListNode *head;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;

public:
    Solution(ListNode *head) : head(head), gen(std::random_device{}()), dis(0, std::numeric_limits<int>::max()) {
    }

    int getRandom() {
        int ret = 0;
        int i = 1;
        ListNode *node = head;
        while (node) {
            int x = dis(gen);
            if (x % i == 0)
                ret = node->val;

            node = node->next;
            ++i;
        }

        return ret;
    }
};
