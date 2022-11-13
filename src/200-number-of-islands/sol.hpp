// https://leetcode.cn/problems/number-of-islands/

#pragma once

#include "common.h"

class UnionFind {
    vector<int> parent{};
    int ret = 0;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union_(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        --ret;
        parent[px] = py;
    }

public:
#define IDX(i, j) ((i) * n + j)

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // init disjoint union
        parent = vector<int>(m * n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                parent[IDX(i, j)] = IDX(i, j);
                if (grid[i][j] == '1')
                    ++ret;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '1') continue;

                // skip neighbors on the left and above

                if (i + 1 < m && grid[i + 1][j] == '1') {
                    union_(IDX(i, j), IDX(i + 1, j));
                }
                if (j + 1 < n && grid[i][j + 1] == '1') {
                    union_(IDX(i, j), IDX(i, j + 1));
                }
            }
        }

        return ret;
    }
};

class BFS {
public:
    int numIslands(vector<vector<char>> &grid) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto coord = q.front();
                        q.pop();

                        int ii = coord.first;
                        int jj = coord.second;

                        if (ii > 0 && grid[ii - 1][jj] == '1') {
                            q.push({ii - 1, jj});
                            grid[ii - 1][jj] = '0';
                        }
                        if (ii + 1 < grid.size() && grid[ii + 1][jj] == '1') {
                            q.push({ii + 1, jj});
                            grid[ii + 1][jj] = '0';
                        }
                        if (jj > 0 && grid[ii][jj - 1] == '1') {
                            q.push({ii, jj - 1});
                            grid[ii][jj - 1] = '0';
                        }
                        if (jj + 1 < grid[0].size() && grid[ii][jj + 1] == '1') {
                            q.push({ii, jj + 1});
                            grid[ii][jj + 1] = '0';
                        }
                    }
                    ++ret;
                }
            }
        }

        return ret;
    }
};
