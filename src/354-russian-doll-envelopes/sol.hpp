// https://leetcode.cn/problems/russian-doll-envelopes/description

#pragma once

#include "common.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();

        std::sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) {
                // since we find the largest k in binary search below
                // we will get the smallest envelope height if the width is the same
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        // dp[i] = min element that the longest increasing sequence with length i ends with
        // dp[i] is always < dp[i + 1]
        vector<int> dp(n, 0);

        int cursor = 0;
        dp[cursor] = envelopes[0][1];

        for (int i = 1; i < n; ++i) {
            if (envelopes[i][1] > dp[cursor]) {
                dp[++cursor] = envelopes[i][1];
            } else {
                // find the index k of the last element in dp that is less than nums[i]
                int l = 0;
                int r = cursor;
                int k = -1; // if nothing is found, (k + 1 = 0)-th element is set to the current envelope height
                while (l <= r) {
                    int mid = (l + r) / 2;

                    if (dp[mid] < envelopes[i][1]) {
                        k = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                dp[k + 1] = envelopes[i][1];
            }
        }

        return cursor + 1;
    }
};
