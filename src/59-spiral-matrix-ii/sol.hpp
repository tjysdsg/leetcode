// https://leetcode.cn/problems/spiral-matrix-ii/

#pragma once

#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        int val = 1;
        for (int layer = 0; layer < n / 2; ++layer) {
            for (int i = layer; i < n - layer; ++i) {
                ret[layer][i] = val++;
            }
            for (int i = layer + 1; i < n - layer; ++i) {
                ret[i][n - layer - 1] = val++;
            }
            for (int i = n - layer - 2; i >= layer; --i) {
                ret[n - layer - 1][i] = val++;
            }
            for (int i = n - layer - 2; i >= layer + 1; --i) {
                ret[i][layer] = val++;
            }
        }

        if (n % 2)
            ret[n / 2][n / 2] = val++;
        return ret;
    }
};
