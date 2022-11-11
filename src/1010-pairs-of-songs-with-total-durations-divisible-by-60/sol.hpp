// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#pragma once

#include "common.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int n = time.size();
        // unordered_map<int, int> m{};
        vector<int> m(60, 0);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int t = time[i] % 60;
            int key = 60 - t;
            ret += m[key == 60 ? 0 : key];
            m[t]++;
        }
        return ret;
    }
};
