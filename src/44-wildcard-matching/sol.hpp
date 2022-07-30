// https://leetcode-cn.com/problems/regular-expression-matching/

#pragma once

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::vector;

// TODO: greedy
// TODO: Aho-Corasick automaton

class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();

        // dp[i+1][j+1] = whether str[i] matches pattern[j]
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
        dp[0][0] = true;

        for (int i = -1; i < ns; ++i) {
            for (int j = 0; j < np; ++j) { // dp[xx][0] is always false
                bool matched = false;

                if (p[j] == '*') {
                    if (i >= 0)
                        matched |= dp[i][j + 1] || dp[i][j]; // * matches any char

                    matched |= dp[i + 1][j]; // * doesn't match anything
                } else if (i >= 0) {
                    if (p[j] == '?') // ? matches any single char
                        matched |= dp[i][j];
                    else
                        matched = s[i] == p[j] && dp[i][j];
                }

                dp[i + 1][j + 1] = matched;
            }
        }

        return dp[ns][np];
    }
};
