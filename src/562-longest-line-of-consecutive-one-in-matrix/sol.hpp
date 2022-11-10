// https://leetcode.cn/problems/longest-line-of-consecutive-one-in-matrix/

#pragma once

#include "common.h"

class Solution {
public:
    int longestLine(vector<vector<int>> &mat) {
        int ret = 0;
        int m = mat.size();
        assert(m);
        int n = mat[0].size();

        vector<int> dp_v(n + 1, 0);
        vector<int> dp_diag(n + 1, 0);
        vector<int> dp_anti(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> dp_h(n + 1, 0);
            vector<int> dp_diag_copy(dp_diag);
            for (int j = 1; j <= n; ++j) {
                if (mat[i][j - 1] == 0) {
                    dp_v[j] = 0;
                    dp_diag[j] = 0;
                    dp_anti[j] = 0;
                    continue;
                }

                dp_h[j] = dp_h[j - 1] + 1;
                dp_v[j] += 1;
                dp_diag[j] = dp_diag_copy[j - 1] + 1;
                dp_anti[j] = j < n ? dp_anti[j + 1] + 1 : 1;

                ret = std::max(ret, dp_h[j]);
                ret = std::max(ret, dp_v[j]);
                ret = std::max(ret, dp_diag[j]);
                ret = std::max(ret, dp_anti[j]);
            }
        }

        return ret;
    }
};
