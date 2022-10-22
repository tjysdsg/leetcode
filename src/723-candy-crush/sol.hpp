// https://leetcode.cn/problems/candy-crush/

#pragma once

#include "common.h"

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int R = board.size(), C = board[0].size();
        bool todo = false;

        do {
            todo = false;

            // scan horizontally
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c + 2 < C; ++c) {
                    int v = std::abs(board[r][c]);
                    if (v != 0 && v == std::abs(board[r][c + 1]) && v == std::abs(board[r][c + 2])) {
                        board[r][c] = board[r][c + 1] = board[r][c + 2] = -v;
                        todo = true;
                    }
                }
            }

            // scan vertically
            for (int r = 0; r + 2 < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    int v = std::abs(board[r][c]);
                    if (v != 0 && v == std::abs(board[r + 1][c]) && v == std::abs(board[r + 2][c])) {
                        board[r][c] = board[r + 1][c] = board[r + 2][c] = -v;
                        todo = true;
                    }
                }
            }

            // for each column, move candy down if there is empty space below
            for (int c = 0; c < C; ++c) {
                int base = R - 1;
                for (int r = R - 1; r >= 0; --r)
                    if (board[r][c] > 0)
                        board[base--][c] = board[r][c];

                while (base >= 0) // set all elements above base to empty
                    board[base--][c] = 0;
            }
        } while (todo);

        return board;
    }
};
