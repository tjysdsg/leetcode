// https://leetcode.cn/problems/shortest-path-in-binary-matrix/

#pragma once

#include "common.h"

class Solution {
    static constexpr int directions[8][2]{
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  -1},
            {0,  1},
            {1,  -1},
            {1,  0},
            {1,  1},
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int m = grid.size();
        assert(m);
        int n = grid[0].size();

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) return -1;

        queue<pair<int, int>> q{};
        q.emplace(0, 0);

        int step = 0;
        while (!q.empty()) {
            ++step;
            int size = q.size();

            for (int _ = 0; _ < size; ++_) {
                auto coord = q.front();
                int i = coord.first;
                int j = coord.second;
                q.pop();

                if (grid[i][j]) continue; // visited

                assert(grid[i][j] == 0);
                if (i == m - 1 && j == n - 1) return step;
                grid[i][j] = 1;

                for (const auto &dir: directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                        q.emplace(ni, nj);
                    }
                }
            }
        }

        return -1;
    }
};
