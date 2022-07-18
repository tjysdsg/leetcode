// https://leetcode-cn.com/problems/roman-to-integer/

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

inline int normal_conversion(char c) {
    int ret = 0;
    switch (c) {
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        default:
            break;
    }
    return ret;
}

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        int n = s.length();
        int i = 0;
        while (i < n) {
            int curr = -1;

            if (i < n - 1) { // check subtraction
                if (s[i] == 'I' && s[i + 1] == 'V') curr = 4;
                else if (s[i] == 'I' && s[i + 1] == 'X') curr = 9;
                else if (s[i] == 'X' && s[i + 1] == 'L') curr = 40;
                else if (s[i] == 'X' && s[i + 1] == 'C') curr = 90;
                else if (s[i] == 'C' && s[i + 1] == 'D') curr = 400;
                else if (s[i] == 'C' && s[i + 1] == 'M') curr = 900;
            }

            if (curr == -1) // no subtraction
                curr = normal_conversion(s[i]);
            else // skip 2 when there is subtraction
                ++i;

            ++i;
            res += curr;
        }
        return res;
    }
};
