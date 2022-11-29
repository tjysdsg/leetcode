// https://leetcode.cn/problems/word-break/

#pragma once

#include "common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        int max_str_len = 0;
        for (const string &e: wordDict) {
            max_str_len = std::max(max_str_len, (int) e.length());
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = std::max(0, i - max_str_len); j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
