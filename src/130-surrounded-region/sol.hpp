// https://leetcode.cn/problems/surrounded-regions

#pragma once

#include "common.h"

class Solution {
private:
    int rows = -1;
    int cols = -1;
public:
    void solve(vector<vector<char>> &board) {
        rows = board.size();
        cols = board[0].size();

        // vertical edges
        for (int r = 0; r < rows; ++r) {
            for (int c: {0, cols - 1}) {
                dfs(board, r, c);
            }
        }

        // horizontal edges
        for (int c = 0; c < cols; ++c) {
            for (int r: {0, rows - 1}) {
                dfs(board, r, c);
            }
        }

        // replace surrounded regions
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'A') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    // no need to check if visited
    void dfs(vector<vector<char>> &board, int r, int c) {
        if (board[r][c] != 'O') return;
        // std::cout << "(" << r << ", " << c << ")" << '\n';
        board[r][c] = 'A';

        if (r > 0) {
            dfs(board, r - 1, c);
        }
        if (r < rows - 1) {
            dfs(board, r + 1, c);
        }
        if (c > 0) {
            dfs(board, r, c - 1);
        }
        if (c < cols - 1) {
            dfs(board, r, c + 1);
        }
    }
};
