// https://leetcode.com/problems/optimal-account-balancing

#pragma once

#include "common.h"

class Solution {
private:
    vector<int> dp{}; // set of persons (bitmask) => max number of subgroups that have balance of 0
    int n = 0; // number of persons
    unordered_map<int, int> balance{}; // person => its total balance

public:
    int minTransfers(vector<vector<int>> &transactions) {
        for (const auto &t: transactions) {
            int from = t[0];
            int to = t[1];
            int amount = t[2];

            balance[from] -= amount;
            balance[to] += amount;

            n = std::max(n, from);
            n = std::max(n, to);
        }

        // for (auto p: balance) {
        //     std::cout << p.first << "=" << p.second << '\n';
        // }

        int comb = 1 << n; // number of combinations
        dp = vector<int>(comb, -1);
        dp[0] = 0;

        // every subgroup that has balance of 0 saves us 1 transaction
        // if no such subgroup, we need n transactions (everyone gives a single person their debt)
        return n - max_groups((1 << n) - 1);
    }

    int max_groups(int bitmask) {
        if (dp[bitmask] != -1) return dp[bitmask]; // cached

        // dp rule:
        // if total balance of bitmask is 0: dp[bitmask] = max_i{ dp[bitmask minus person i] } + 1
        // otherwise:                        dp[bitmask] = max_i{ dp[bitmask minus person i] }

        int total_balance = 0;
        int subgroups = 0;
        for (int i = 0; i < n; ++i) {
            int bit = (1 << i);
            if ((bitmask & bit) == 0) continue; // person not in bitmask

            total_balance += balance[i];

            int m = bitmask ^ bit; // new mask without this person
            subgroups = std::max(subgroups, max_groups(m));
        }

        dp[bitmask] = subgroups + (total_balance == 0 ? 1 : 0);
        return dp[bitmask];
    }
};
