// https://leetcode.cn/problems/merge-intervals/

#pragma once

#include "common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ret{};
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > r) {
                ret.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = std::max(r, intervals[i][1]);
            }
        }

        ret.push_back({l, r});
        return ret;
    }
};
