// https://leetcode.cn/problems/range-addition/

#pragma once

#include <numeric>
#include "common.h"

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> delta(length, 0); // delta[i] = diff between i-th element and (i-1)-th element
        for (auto x: updates) {
            delta[x[0]] += x[2];
            if (x[1] + 1 < length)
                delta[x[1] + 1] -= x[2];
        }

        std::partial_sum(delta.begin(), delta.end(), delta.begin());
        return delta;
    }
};
