// https://leetcode-cn.com/problems/edit-distance/

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using std::string;
using std::cout;
using std::vector;

#define MAX_WORD_LEN 500
#define MATCH(x, y) ((x) == (y)? 0 : 1)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        // dp[i][j] is the cost of matching the i-th letter of word1 and j-th letter of word2
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        dp[0][0] = 0; // two empty strings

        // initialize the first row and column to avoid if statements in the main loop
        for (int j = 1; j <= len2; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] = i;
        }

        // main loop
        for (int i = 1; i <= len1; ++i) { // the first column
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = std::min(
                            std::min(
                                    dp[i - 1][j], // insertion/deletion
                                    dp[i - 1][j - 1] // substitution or match
                            ),
                            dp[i][j - 1] // insertion/deletion
                    ) + 1;
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
