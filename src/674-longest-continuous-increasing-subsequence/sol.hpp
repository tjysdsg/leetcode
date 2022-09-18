// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/

#pragma once

#include "common.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int ret = 1;
        int n = nums.size();
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++count;
            } else {
                count = 1;
            }
            ret = std::max(ret, count);
        }

        return ret;
    }
};
