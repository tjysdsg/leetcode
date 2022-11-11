// https://leetcode.cn/problems/maximal-square/

#pragma once

#include "common.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        assert(m);
        int n = matrix[0].size();

        int ret = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int prev_size = dp[i - 1][j - 1];
                prev_size = std::min(prev_size, dp[i][j - 1]);
                prev_size = std::min(prev_size, dp[i - 1][j]);

                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = prev_size + 1;
                    ret = std::max(ret, dp[i][j] * dp[i][j]);
                }
            }
        }

        return ret;
    }
};
