// https://leetcode.cn/problems/palindromic-substrings/

#pragma once

#include "common.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 0; i < 2 * n - 1; ++i) { // there are (2 * n - 1) palindromic centers
            int l = i / 2; // start of center
            int r = i / 2 + i % 2; // end of center

            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ret;
            }
        }

        return ret;
    }
};
