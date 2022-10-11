// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/

#pragma once

#include "common.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        for (char c: s) {
            if (!v.empty() && v.back().first == c) {
                if (++v.back().second == k)
                    v.pop_back();
                continue;
            }
            v.emplace_back(std::make_pair(c, 1));
        }

        string ret = "";
        for (auto &e: v) {
            char c = e.first;
            int count = e.second;
            ret += string(count, c);
        }
        return ret;
    }
};
