// https://leetcode.cn/problems/decode-string/

#pragma once

#include "common.h"

class Solution {
public:
    string decodeString(string s) {
        string curr = "";
        string ret = "";
        stack<pair<int, string>> st{};
        int times = 0;
        for (char c: s) {
            if (c == '[') {
                st.emplace(times, curr);
                times = 0;
                curr = "";
            } else if (c == ']') {
                assert(!st.empty());
                auto p = st.top();
                st.pop();
                int n = p.first;
                string prefix = p.second;

                string tmp = curr;
                for (int _ = 0; _ < n - 1; ++_) tmp.append(curr);
                if (st.empty()) {
                    ret += tmp;
                    curr = "";
                } else {
                    curr = prefix + tmp;
                }

                times = 0;
            } else if (c >= '0' && c <= '9') {
                times = times * 10 + c - '0';
            } else {
                if (st.empty()) ret += c;
                else curr += c;
            }
        }

        return ret;
    }
};
