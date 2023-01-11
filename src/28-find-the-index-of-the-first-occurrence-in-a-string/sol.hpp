// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#pragma once

#include "common.h"

class Solution {
public:
    int strStr(string s, string pat) {
        int len_pat = pat.length();
        int len_s = s.length();

        // partial match table
        vector<int> pmt(len_pat, 0);
        int i = 1;
        int pre_i = 0;
        while (i < len_pat) {
            if (pat[i] == pat[pre_i]) {
                pmt[i++] = ++pre_i;
            } else {
                if (pre_i > 0)
                    pre_i = pmt[pre_i - 1];
                else
                    ++i;
            }
        }

        // search
        int pat_i = 0;
        int s_i = 0;
        while (pat_i < len_pat && s_i < len_s) {
            if (s[s_i] == pat[pat_i]) {
                ++s_i;
                ++pat_i;
            } else {
                if (pat_i > 0)
                    pat_i = pmt[pat_i - 1];
                else
                    ++s_i;
            }

            if (pat_i == len_pat)
                return s_i - pat_i;
        }

        return -1;
    }
};
