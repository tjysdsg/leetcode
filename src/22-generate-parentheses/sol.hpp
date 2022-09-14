// https://leetcode.cn/problems/generate-parentheses/

#pragma once

#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", n, n);
        return ret;
    }

    void generate(vector<string> &res, string s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        if (left > right) return; // remaining left cannot be more than remaining right, e.g. ))( is invalid

        if (left == right) {
            generate(res, s + "(", left - 1, right);
        } else {
            if (left > 0)
                generate(res, s + "(", left - 1, right);
            if (right > 0)
                generate(res, s + ")", left, right - 1);
        }

    }
};
