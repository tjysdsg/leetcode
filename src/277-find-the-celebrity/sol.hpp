// https://leetcode.cn/problems/find-the-celebrity

#pragma once

#include "common.h"

bool knows(int a, int b) { return false; }

class Solution {
public:
    int findCelebrity(int n) {
        int curr = 0; // current possible celebrity
        for (int i = 1; i < n; ++i) {
            if (knows(curr, i)) {  // curr is definitely not a celebrity
                curr = i;
            } // otherwise, i is definitely not a celebrity
        }

        // check if curr is actually a celebrity
        for (int i = 0; i < n; ++i) {
            if (!knows(i, curr) || (curr != i && knows(curr, i)))
                return -1;
        }

        return curr;
    }
};
