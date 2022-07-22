// https://leetcode.cn/problems/number-of-islands/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        queue<std::pair<int, int>> q;

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
