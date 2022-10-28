// https://leetcode.cn/problems/n-queens/

#pragma once

#include "common.h"

class Solution {
    vector<vector<string>> ans{};

    vector<string> create_board(int n, const vector<int> &queens) {
        vector<string> board{};
        for (int i = 0; i < n; ++i) {
            string s(n, '.');
            s[queens[i]] = 'Q';
            board.push_back(s);
        }
        return board;
    }

    void
    backtrack(
            int n, vector<int> &queens, int row,
            unordered_set<int> &occupied_cols, unordered_set<int> &occupied_diag1, unordered_set<int> &occupied_diag2
    ) {
        if (row >= n) { // all queens are set
            ans.push_back(create_board(n, queens));
            return;
        }

        for (int i = 0; i < n; ++i) {
            int diag1 = row - i;
            int diag2 = row + i;
            if (occupied_cols.find(i) != occupied_cols.end())
                continue;
            if (occupied_diag1.find(diag1) != occupied_diag1.end() ||
                occupied_diag2.find(diag2) != occupied_diag2.end())
                continue;

            queens[row] = i;
            occupied_cols.insert(i);
            occupied_diag1.insert(diag1);
            occupied_diag2.insert(diag2);

            backtrack(n, queens, row + 1, occupied_cols, occupied_diag1, occupied_diag2);

            occupied_cols.erase(i);
            occupied_diag1.erase(diag1);
            occupied_diag2.erase(diag2);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, 0);
        unordered_set<int> a{};
        unordered_set<int> b{};
        unordered_set<int> c{};
        backtrack(n, queens, 0, a, b, c);
        return ans;
    }
};
