// https://leetcode.cn/problems/random-pick-index/

#pragma once

#include "common.h"

#include <limits>
#include <random>

class Solution {
    vector<int> nums;

public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ret = 0;

        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                ++count;
                if (rand() % count == 0) {
                    ret = i;
                }
            }
        }

        return ret;
    }
};
