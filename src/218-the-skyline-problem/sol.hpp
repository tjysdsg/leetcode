// https://leetcode.cn/problems/the-skyline-problem/

#pragma once

#include "common.h"

class Solution {
private:
    /// left/right boundaries of buildings
    vector<int> boundaries{};

    /// max heap of {height, x-coordinates of buildings' right boundaries}, sorted on height
    priority_queue<pair<int, int>> q{};

public:

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        for (const auto &v: buildings) {
            boundaries.push_back(v[0]);
            boundaries.push_back(v[1]);
        }
        std::sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ret{};
        int n = buildings.size();
        int i = 0;
        for (int b: boundaries) {
            while (i < n) {
                int left = buildings[i][0];
                int right = buildings[i][1];
                int height = buildings[i][2];

                if (left > b) {
                    break;
                } else if (right > b) {
                    q.emplace(height, right);
                }

                ++i;
            }

            while (!q.empty() && q.top().second <= b) {
                q.pop();
            }

            int new_height = 0;
            if (!q.empty())
                new_height = std::max(new_height, q.top().first);

            if (ret.empty() || new_height != ret.back()[1]) {
                ret.push_back({b, new_height});
            }
        }

        return ret;
    }
};
