// https://leetcode.cn/problems/word-break-ii/

#pragma once

#include "common.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();
        unordered_map<int, vector<string>> dp{};
        dp[0] = {};

        int max_str_len = 0;
        for (const string &e: wordDict) {
            max_str_len = std::max(max_str_len, (int) e.length());
        }

        for (int i = 1; i <= n; ++i) {
            vector<string> curr{};
            for (int j = std::max(0, i - max_str_len); j < i; ++j) {
                auto it = dp.find(j);
                string word = s.substr(j, i - j);
                if (it != dp.end() && dict.find(word) != dict.end()) {
                    if (j == 0) {
                        curr.push_back(word);
                    } else {
                        vector<string> valid = it->second;
                        for (string v: valid) {
                            curr.push_back(v + " " + word);
                        }
                    }
                }
            }
            dp[i] = curr;
        }

        return dp[n];
    }
};
