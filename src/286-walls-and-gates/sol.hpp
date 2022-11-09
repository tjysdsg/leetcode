// https://leetcode.cn/problems/walls-and-gates/

#pragma once

#include "common.h"

class Solution {
    const int dirs[4][2]{
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1},
    };

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        assert(m);
        int n = rooms[0].size();

        queue<pair<int, int>> q{};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int _ = 0; _ < size; ++_) {
                auto coord = q.front();
                q.pop();

                int i = coord.first, j = coord.second;
                for (auto dir: dirs) {
                    int ni = i + dir[0], nj = j + dir[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && rooms[ni][nj] == 2147483647) {
                        rooms[ni][nj] = dist;
                        q.emplace(ni, nj);
                    }
                }
            }

            ++dist;
        }
    }
};
