// https://leetcode.cn/problems/insert-interval/

#pragma once

#include "common.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ret;

        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        for (const auto &interval: intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    ret.push_back({left, right});
                    placed = true;
                }
                ret.push_back(interval);
            } else if (interval[1] < left) {
                ret.push_back(interval);
            } else {
                left = std::min(left, interval[0]);
                right = std::max(right, interval[1]);
            }
        }

        if (!placed) {
            ret.push_back({left, right});
        }
        return ret;
    }
};
