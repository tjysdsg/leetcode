// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::set;
using std::stack;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();
        if (n <= 1) return n;

        map<char, int> c2i;

        int len = 1;
        int ret = 1;
        c2i[s[0]] = 0;
        for (int i = 1; i < n; ++i) {
            char c = s[i];

            auto q = c2i.find(c);
            if (q == c2i.end()) {
                ++len;
            } else { // move the starting point to the next position after the repeating char
                int start = c2i[c] + 1;

                // update char set
                for (int j = i - len; j < start; ++j)
                    c2i.erase(s[j]);

                len = i - start + 1; // update len
            }

            c2i[c] = i;
            ret = std::max(ret, len);
        }

        return ret;
    }
};
