// https://leetcode.cn/problems/minimum-increment-to-make-array-unique/

#pragma once

#include "common.h"

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        int n = nums.size();
        int n_duplicates = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                ++n_duplicates;
                ret -= nums[i];
            } else {
                int n_incr = std::min(n_duplicates, nums[i] - nums[i - 1] - 1);
                ret += n_incr * (nums[i - 1] + 1 + nums[i - 1] + n_incr) / 2;
                n_duplicates -= n_incr;
            }
        }

        ret += n_duplicates * (nums.back() + 1 + nums.back() + n_duplicates) / 2;
        return ret;
    }
};
