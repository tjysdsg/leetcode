// https://leetcode.cn/problems/maximal-rectangle/

#pragma once

#include "common.h"

// TODO: monotonic stack

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int ret = 0;

        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        // dp[i][j] = # of consecutive 1's before (inclusive) element (i,j)
        vector<vector<int>> dp(n_rows, vector<int>(n_cols, 0));
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }

                // go upwards and find the larges rectangle whose bottom-right most corner is (i,j)
                // area = min_width * (i - k + 1)
                int min_width = dp[i][j];
                for (int k = i; k >= 0; --k) {
                    if (dp[k][j] == 0) break;

                    min_width = std::min(min_width, dp[k][j]);
                    ret = std::max(ret, min_width * (i - k + 1));
                }
            }
        }

        return ret;
    }
};
