// https://leetcode.cn/problems/longest-increasing-subsequence/description/

#pragma once

#include "common.h"

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums) {
        int n = nums.size();

        // dp[i] = length of LTS that ends at i
        vector<int> dp(n, 0);
        dp[0] = 1;

        int ret = 1;
        for (int i = 1; i < n; ++i) {
            int prev = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    prev = std::max(prev, dp[j]);
                }
            }

            dp[i] = prev + 1;
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
