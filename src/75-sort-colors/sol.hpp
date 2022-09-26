// https://leetcode.cn/problems/sort-colors/

#pragma once

#include "common.h"

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int p0 = 0, p1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[p0]);
                if (p0 < p1)
                    std::swap(nums[i], nums[p1]);
                ++p0;
                ++p1;
            } else if (nums[i] == 1) {
                std::swap(nums[i], nums[p1++]);
            }
        }
    }
};
