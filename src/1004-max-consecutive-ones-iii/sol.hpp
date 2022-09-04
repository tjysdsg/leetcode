// https://leetcode.cn/problems/max-consecutive-ones-iii/

#pragma once

#include "common.h"

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size();
        int ret = 0;

        int j_sum = 0;
        int i_sum = 0;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            j_sum += 1 - nums[j];

            while (j_sum - i_sum > k) {
                i_sum += 1 - nums[i++];
            }

            ret = std::max(ret, j - i + 1);
        }

        return ret;
    }
};
