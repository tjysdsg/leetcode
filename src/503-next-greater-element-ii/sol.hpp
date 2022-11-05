// https://leetcode.cn/problems/next-greater-element-ii/

#pragma once

#include "common.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int idx = i % n;
            while (!s.empty() && nums[s.top()] < nums[idx]) {
                ret[s.top()] = nums[idx];
                s.pop();
            }
            s.push(idx);
        }
        return ret;
    }
};
