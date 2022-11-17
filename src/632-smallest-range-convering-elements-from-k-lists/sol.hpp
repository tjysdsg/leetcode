// https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists

#pragma once

#include "common.h"

class Solution {
    vector<int> idx{};
    vector<int> lengths{};
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int k = nums.size();
        idx = vector<int>(k, 0);

        // lengths[i] = len(nums[i])
        lengths = vector<int>(k, 0);
        for (int i = 0; i < k; ++i) {
            lengths[i] = nums[i].size();
        }

        // sorted ascending ly
        auto cmp = [&](const int &a, const int &b) {
            return nums[a][idx[a]] > nums[b][idx[b]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

        int max_ = INT32_MIN;
        for (int i = 0; i < k; ++i) {
            int num = nums[i][idx[i]];
            if (num > max_) max_ = num;
            q.push(i);
        }
        int range_i = nums[q.top()][idx[q.top()]];
        int range_j = max_;

        while (true) {
            int min_idx = q.top();
            q.pop();

            int min_ = nums[min_idx][idx[min_idx]];
            if (max_ - min_ < range_j - range_i) {
                range_i = min_;
                range_j = max_;
            }

            if (++idx[min_idx] >= lengths[min_idx]) break;
            max_ = std::max(max_, nums[min_idx][idx[min_idx]]);
            q.push(min_idx);
        }
        return {range_i, range_j};
    }
};
