// https://leetcode.cn/problems/valid-parentheses/

#pragma once

#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pair{
                {']', '['},
                {'}', '{'},
                {')', '('},
        };

        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                char p = pair[c];

                if (!st.empty() && p == st.top()) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        return st.empty();
    }
};
