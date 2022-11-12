// https://leetcode.cn/problems/count-and-say/

#pragma once

#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int _ = 1; _ < n; ++_) {
            string new_s = "";
            char curr = ' ';
            int count = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (curr != s[i]) {
                    if (count) {
                        new_s += '0' + count;
                        new_s += curr;
                    }
                    curr = s[i];
                    count = 1;
                } else {
                    ++count;
                }
            }

            new_s += '0' + count;
            new_s += curr;
            s = new_s;
            cout << s << '\n';
        }

        return s;
    }
};
