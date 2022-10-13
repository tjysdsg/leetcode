// https://leetcode.cn/problems/minimize-result-by-adding-parentheses-to-expression/

#pragma once

#include "common.h"

class Solution {
public:
    int calculate(const string &exp, int i, int j, int add) {
        int a = 1, d = 1;
        if (i > 0)
            a = atoi(exp.substr(0, i).c_str());
        if (j < exp.length())
            d = atoi(exp.substr(j).c_str());

        int b = atoi(exp.substr(i, add - i).c_str());
        int c = atoi(exp.substr(add + 1, j - add - 1).c_str());

        return a * (b + c) * d;
    }

    string minimizeResult(string exp) {
        int add = exp.find('+');
        assert(add != string::npos);

        int min_res = INT32_MAX;
        int n = exp.length();
        int argmin_i = 0;
        int argmin_j = n;

        // a(b+c)d
        // "ab+cd"
        // i = location of b
        // j = location of d
        for (int i = 0; i < add; ++i) {
            for (int j = n; j > add + 1; --j) {
                int res = calculate(exp, i, j, add);

                if (min_res > res) {
                    argmin_i = i;
                    argmin_j = j;
                    min_res = res;
                }
            }
        }

        string ret = exp;
        ret.insert(ret.begin() + argmin_j, ')');
        ret.insert(ret.begin() + argmin_i, '(');
        return ret;
    }
};
