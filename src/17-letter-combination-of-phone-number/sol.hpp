// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#pragma once

#include "common.h"

class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
        vector<string> ret;
        if (digits.empty()) return ret;

        ret.reserve(pow(3, digits.length()));
        backtrack(ret, "", digits, 0);
        return ret;
    }

    void backtrack(vector<string> &combs, string s, const string &digits, size_t i) {
        if (s.length() == digits.length()) {
            combs.push_back(s);
            return;
        }

        string letters = m[digits[i]];
        for (char l: letters) {
            s.push_back(l);
            backtrack(combs, s, digits, i + 1);
            s.pop_back();
        }
    }

private:
    unordered_map<char, string> m{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
};
