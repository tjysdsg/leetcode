// https://leetcode.cn/problems/permutations/

#pragma once

#include "common.h"

class Solution {
    vector<vector<int>> ans{};

public:
    vector<vector<int>> permute(vector<int> &nums) {
        backtrack(nums, nums.size(), 0);
        return ans;
    }

    void backtrack(vector<int> &v, int n, int i) {
        if (i >= n) {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < n; ++j) {
            std::swap(v[i], v[j]);
            backtrack(v, n, i + 1);
            std::swap(v[i], v[j]);
        }
    }
};
