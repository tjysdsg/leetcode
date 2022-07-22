// https://leetcode.cn/problems/spiral-matrix/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        vector<int> ret{};

        int direction = 1; // 0 up, 1 right, 2 down, 3 left

        // boundaries
        int top = 0;
        int right = n_cols - 1;
        int bottom = n_rows - 1;
        int left = 0;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                ret.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                ret.push_back(matrix[i][right]);
            }

            if (top < bottom) {
                for (int i = right - 1; i >= left; --i) {
                    ret.push_back(matrix[bottom][i]);
                }
            }
            if (left < right) {
                for (int i = bottom - 1; i >= top + 1; --i) {
                    ret.push_back(matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }
        return ret;
    }
};
