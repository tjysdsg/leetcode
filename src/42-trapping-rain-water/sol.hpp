// https://leetcode.cn/problems/trapping-rain-water/

#pragma once

#include "common.h"

// TODO: dp
// TODO: monotonic stack

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_left = 0;
        int max_right = 0;

        int ret = 0;
        while (left <= right) {
            max_left = std::max(max_left, height[left]);
            max_right = std::max(max_right, height[right]);

            if (height[left] <= height[right]) {
                ret += max_left - height[left];
                ++left;
            } else {
                ret += max_right - height[right];
                --right;
            }
        }

        return ret;
    }
};
