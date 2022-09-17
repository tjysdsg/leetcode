// https://leetcode.cn/problems/jump-game/

#pragma once

#include "common.h"

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int furthest = 0;
        int prev = -1;

        while (furthest < n - 1) {
            if (prev == furthest) return false;

            int p = furthest;
            for (int i = prev + 1; i <= furthest; ++i) {
                p = std::max(p, i + nums[i]);
            }
            prev = furthest;
            furthest = std::min(n - 1, p);
        }
        return true;
    }
};
