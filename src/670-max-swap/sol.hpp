// https://leetcode.cn/problems/maximum-swap/

#pragma once

#include "common.h"

class Solution {
public:
    int maximumSwap(int num) {
        string s = std::to_string(num);
        int n = s.length();

        vector<int> v(n, -1);
        int max_v = -1;
        int max_i = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] > max_v) {
                max_v = s[i];
                max_i = i;
            }

            v[i] = max_i;
        }

        for (int i = 0; i < n - 1; ++i) {
            max_i = v[i + 1];
            max_v = s[max_i];
            if (max_v > s[i]) {
                std::swap(s[i], s[max_i]);
                return std::stoi(s);
            }
        }

        return num;
    }
};
