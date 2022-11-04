// https://leetcode.cn/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#pragma once

#include "common.h"

class Solution {
    vector<vector<int>> g;
    int m = 0;
    int n = 0;
    int res = -1;
    map<pair<int, int>, int> visited{};

    struct Cell {
        int i;
        int j;
        int remain_k;

        Cell(int remain_k, int i, int j) : i(i), j(j), remain_k(remain_k) {}
    };

public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        g = grid;
        m = grid.size();
        n = grid[0].size();

        queue<Cell> q;
        q.emplace(k, 0, 0);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int _ = 0; _ < size; ++_) {
                Cell c = q.front();
                q.pop();
                int i = c.i, j = c.j, remain_k = c.remain_k;

                if (i == m - 1 && j == n - 1) {
                    return steps;
                }

                auto it = visited.find({i, j});
                if (it != visited.end() && it->second >= remain_k) continue;

                visited[{i, j}] = remain_k;
                // cout << steps << ": " << i << ',' << j << '\n';

                // up
                if (i > 0) {
                    if (g[i - 1][j] == 1) { // obstacle
                        if (remain_k) {
                            q.emplace(remain_k - 1, i - 1, j);
                        }
                    } else {
                        q.emplace(remain_k, i - 1, j);
                    }
                }
                // down
                if (i < m - 1) {
                    if (g[i + 1][j] == 1) { // obstacle
                        if (remain_k)
                            q.emplace(remain_k - 1, i + 1, j);
                    } else {
                        q.emplace(remain_k, i + 1, j);
                    }
                }
                // left
                if (j > 0) {
                    if (g[i][j - 1] == 1) { // obstacle
                        if (remain_k)
                            q.emplace(remain_k - 1, i, j - 1);
                    } else {
                        q.emplace(remain_k, i, j - 1);
                    }
                }
                // right
                if (j < n - 1) {
                    if (g[i][j + 1] == 1) { // obstacle
                        if (remain_k)
                            q.emplace(remain_k - 1, i, j + 1);
                    } else {
                        q.emplace(remain_k, i, j + 1);
                    }
                }
            }

            ++steps;
        }

        return res;
    }
};
