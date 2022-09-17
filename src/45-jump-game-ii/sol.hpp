// https://leetcode.cn/problems/jump-game-ii/

#pragma once

#include "common.h"

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) { return 0; }

        int furthest = 0;
        int prev = -1;
        int step = 0;
        while (furthest < n - 1) {
            int p = furthest;
            for (int j = prev + 1; j <= furthest; ++j) {
                p = std::max(p, j + nums[j]);
            }
            prev = furthest;
            furthest = std::min(n - 1, p);
            ++step;
        }

        return step;
    }
};
