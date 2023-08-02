// https://leetcode.cn/problems/longest-increasing-subsequence/description/

#pragma once

#include "common.h"

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums) {
        int n = nums.size();

        // dp[i] = min element that LIS with length i ends with
        // dp[i] is always < dp[i + 1]
        vector<int> dp(n, 0);

        int cursor = 0;
        dp[cursor] = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > dp[cursor]) {
                dp[++cursor] = nums[i];
            } else {
                // find the index k of the last element in dp that is less than nums[i]
                int l = 0;
                int r = cursor;
                int k = -1; // if nothing is found, (k + 1 = 0)-th element is set to nums[i]
                while (l <= r) {
                    int mid = (l + r) / 2;

                    if (dp[mid] < nums[i]) {
                        k = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                // set (k+1)-th element in dp to nums[i]
                dp[k + 1] = nums[i];
            }
        }

        return cursor + 1;
    }
};

class DP {
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
