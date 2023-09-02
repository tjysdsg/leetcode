// https://leetcode.cn/problems/ipo

#pragma once

#include "common.h"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();

        priority_queue<int, vector<int>> q{};
        vector<pair<int, int>> proj{};

        for (int i = 0; i < n; ++i) {
            proj.emplace_back(capital[i], profits[i]);
        }
        std::sort(proj.begin(), proj.end());

        int money = w;
        int p = 0;
        for (int i = 0; i < k; ++i) {
            while (p < n && proj[p].first <= money) {
                q.push(proj[p].second);
                ++p;
            }

            if (!q.empty()) {
                money += q.top();
                q.pop();
            } else {
                break;
            }
        }

        return money;
    }
};
