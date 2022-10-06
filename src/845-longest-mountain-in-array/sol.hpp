// https://leetcode.cn/problems/longest-mountain-in-array/

#pragma once

#include "common.h"

class Solution {
public:
    int longestMountain(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int delta = 0;
        int prev_delta = 0;
        int i = 0;
        bool found = false;
        int ret = 0;

        for (int j = 1; j < n; ++j) {
            prev_delta = delta;
            delta = arr[j] - arr[j - 1];

            if (delta > 0 && prev_delta < 0) { // mountain ends
                if (found) ret = std::max(ret, j - i);
                found = false;
                i = j - 1;
            } else if (delta < 0 && prev_delta > 0) { // mountain top found
                found = true;
            } else if (delta == 0) {
                if (found) ret = std::max(ret, j - i);
                found = false;
                i = j;
            }
        }

        if (found) ret = std::max(ret, n - i);
        return ret;
    }
};
