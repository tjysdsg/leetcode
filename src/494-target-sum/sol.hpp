// https://leetcode.cn/problems/target-sum/

#pragma once

#include <numeric>
#include "common.h"

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2) return 0;

        int neg_sum = (sum - target) / 2;
        int n = nums.size();

        // dp[i][j]: how many ways we can sum nums [0, i-1] to get j
        vector<int> dp(neg_sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = neg_sum; j >= 0; --j) {
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];
            }
        }

        return dp[neg_sum];
    }
};

class Backtrack {
    int ret = 0;
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        backtrack(nums, target, 0, 0);
        return ret;
    }

    void backtrack(vector<int> &nums, int target, int i, int sum) {
        if (i >= nums.size()) {
            if (sum == target) ++ret;
            return;
        }

        // '+'
        sum += nums[i];
        backtrack(nums, target, i + 1, sum);
        sum -= nums[i];

        // '-'
        sum -= nums[i];
        backtrack(nums, target, i + 1, sum);
        // sum += nums[i];
    }
};
