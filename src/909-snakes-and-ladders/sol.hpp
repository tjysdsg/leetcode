// https://leetcode.cn/problems/snakes-and-ladders/

#pragma once

#include "common.h"

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        _rows = board.size();
        assert(_rows > 0);
        _cols = board[0].size();
        int dest = _rows * _cols;

        // for (int i = 1; i <= dest; ++i) {
        //     sq2coord(i);
        // }
        // return 0;

        queue<pair<int, int>> q{};  // {sq, step}
        q.emplace(1, 0);

        set<int> visited{};

        while (!q.empty()) {
            auto [sq, step] = q.front();
            q.pop();

            ++step;
            for (int i = 1; i <= 6; ++i) {
                int next = sq + i;
                auto [r, c] = sq2coord(next);

                if (board[r][c] != -1) {
                    // std::cout << "snake or ladder starting at " << next << "(" << r << ", " << c << ") to "
                    //           << board[r][c] << '\n';
                    next = board[r][c];
                }

                if (next == dest) return step;

                // skip visited
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.emplace(next, step);
                }
            }
        }

        return -1;
    }

private:
    pair<int, int> sq2coord(int sq) {
        int r = (sq - 1) / _cols; // starting from bottom

        int c = (sq - 1) % _cols;
        if (r % 2 != 0) { // right to left
            c = _cols - 1 - c;
        }

        // convert r to start from top
        r = _rows - 1 - r;
        // std::cout << sq << " = (" << r << ", " << c << ")\n";
        return {r, c};
    }

    int _rows = 0;
    int _cols = 0;
};
