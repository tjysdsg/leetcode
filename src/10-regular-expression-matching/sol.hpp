// https://leetcode-cn.com/problems/regular-expression-matching/

#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::vector;

#define MAX_STR_LEN 20
#define MAX_PAT_LEN 30

class Solution {
 public:
  bool isMatch(string str, string pattern) {
    // dp[I][J] = whether str[i] matches pattern[j]
    // I = i + 1
    // J = j + 1
    bool dp[MAX_STR_LEN][MAX_PAT_LEN]{};
    dp[0][0] = true;

    for (int I = 0; I <= str.size(); ++I) {
      for (int J = 1; J <= pattern.size(); ++J) {
        int i = I - 1;
        int j = J - 1;
        dp[I][J] = false;

#define MATCH(str, pattern) ((str) == (pattern) || (pattern) == '.')

        if (pattern[j] == '*') { // a*/.*
          // we can safely assume that j >= 1 according to the problem description
          if (I > 0 && MATCH(str[i], pattern[j - 1])) { // match a character or ignore it
            dp[I][J] = (I > 0 && dp[I - 1][J]) || dp[I][J - 2];
            continue;
          } else { // character can't match, ignore it
            dp[I][J] = dp[I][J - 2];
            continue;
          }
        } else { // regular characters
          if (I > 0 && MATCH(str[i], pattern[j])) {
            dp[I][J] = I > 0 && dp[I - 1][J - 1];
            continue;
          }
        }
      }
    }

    return dp[str.size()][pattern.size()];
  }
};
