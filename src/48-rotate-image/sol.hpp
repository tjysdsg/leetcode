// https://leetcode.cn/problems/rotate-image/

#pragma once

#include "common.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int lo = 0; lo < n / 2; ++lo) { // layer
            for (int i = lo; i < n - 1 - lo; ++i) {
                int r = lo;
                int c = i;
                int tmp = matrix[r][c];

                for (int j = 0; j < 4; ++j) {
                    int new_r = c;
                    int new_c = n - 1 - r;

                    std::swap(matrix[new_r][new_c], tmp);

                    r = new_r;
                    c = new_c;
                }
            }
        }
    }
};
