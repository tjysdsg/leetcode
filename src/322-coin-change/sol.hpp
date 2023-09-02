// https://leetcode.cn/problems/coin-change/

#pragma once

#include "common.h"

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        std::sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, -1); // dp[i] = # of coins need to get amount i

        dp[0] = 0;
        for (int c: coins) {
            if (c <= amount) dp[c] = 1;
            else break;
        }

        for (int i = 1; i <= amount; ++i) {
            for (int c = coins.size() - 1; c >= 0; --c) {
                int coin = coins[c];
                if (coin > i) continue;

                int remain = i - coin;
                if (dp[remain] != -1) {
                    int tmp = dp[remain] + 1;
                    if (dp[i] != -1) tmp = std::min(dp[i], tmp);
                    dp[i] = tmp;
                }
            }
        }

        return dp[amount];
    }
};
