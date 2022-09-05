// https://leetcode.cn/problems/valid-sudoku/

#pragma once

#include "common.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> cols(9, vector<int>(10, 0));
        vector<vector<int>> blocks(9, vector<int>(10, 0));

        for (int i = 0; i < 9; ++i) {
            vector<int> row(10, 0);

            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                int n = board[i][j] - '0';
                if (row[n]++) return false;
                if (cols[j][n]++) return false;
                if (blocks[i / 3 * 3 + j / 3][n]++) return false;
            }
        }

        return true;
    }
};
