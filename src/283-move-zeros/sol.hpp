// https://leetcode.cn/problems/move-zeroes/

#pragma once

#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            nums[idx] = nums[i];
            if (nums[idx]) ++idx;
        }
        for (int i = idx; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
