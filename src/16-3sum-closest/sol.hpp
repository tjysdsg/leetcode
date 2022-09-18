// https://leetcode.cn/problems/3sum-closest/

#pragma once

#include "common.h"

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int ret = 0;
        int n = nums.size();
        int min_dist = 999999;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;

                if (sum > target) {
                    --k;
                } else if (sum < target) {
                    ++j;
                }

                int dist = std::abs(sum - target);
                if (dist < min_dist) {
                    ret = sum;
                    min_dist = dist;
                }
            }
        }

        return ret;
    }
};
