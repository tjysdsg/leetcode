// https://leetcode.cn/problems/partition-equal-subset-sum/

#pragma once

#include "common.h"

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return false;

        // return false if the total sum is not divisible by 2 or the max element is larger than the half
        int max = 0;
        int total = 0;
        for (int s: nums) {
            total += s;
            max = std::max(max, s);
        }
        int half = total / 2;
        if (total % 2 || max > half) return false;

        /* 2D version
        // dp[i][j] = true means numbers in range [0, i] can form a sum of j
        vector<vector<bool>> dp(n, vector<bool>(half + 1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= half; ++j) {
                dp[i][j] = dp[i - 1][j]; // not selecting the current number
                if (j - nums[i] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]]; // selecting the current number
            }
        }
        return dp[n - 1][half];
        */

        // 1D version
        // dp[j] = true means numbers in range [0, i] can form a sum of j
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        dp[nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = half; j >= 1; --j) {
                dp[j] = dp[j]; // not selecting the current number
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]]; // selecting the current number
            }
        }
        return dp[half];
    }
};
