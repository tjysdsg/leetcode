// https://leetcode.cn/problems/sudoku-solver/

#pragma once

#include "common.h"

class Solution {
private:
    vector<pair<int, int>> pos{};
    vector<std::bitset<10>> rows{};
    vector<std::bitset<10>> cols{};
    vector<std::bitset<10>> blocks{};

public:
    void solveSudoku(vector<vector<char>> &board) {
        pos = vector<pair<int, int>>{};
        rows = vector<std::bitset<10>>(9);
        cols = vector<std::bitset<10>>(9);
        blocks = vector<std::bitset<10>>(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    pos.emplace_back(i, j);
                } else {
                    int n = board[i][j] - '0';
                    rows[i].set(n);
                    cols[j].set(n);
                    blocks[i / 3 * 3 + j / 3].set(n);
                }
            }
        }

        dfs(board, 0);
    }

    bool dfs(vector<vector<char>> &board, int pos_i) {
        if (pos_i >= pos.size()) return true;

        int i = pos[pos_i].first;
        int j = pos[pos_i].second;
        int block_i = i / 3 * 3 + j / 3;

        for (int n = 1; n < 10; ++n) {
            if (!rows[i].test(n) && !cols[j].test(n) && !blocks[block_i].test(n)) {
                rows[i].set(n);
                cols[j].set(n);
                blocks[block_i].set(n);
                board[i][j] = n + '0';

                if (dfs(board, pos_i + 1)) {
                    return true;
                }
                rows[i].set(n, false);
                cols[j].set(n, false);
                blocks[block_i].set(n, false);
            }
        }

        return false;
    }
};
