// https://leetcode.cn/problems/leftmost-column-with-at-least-a-one/

#pragma once

#include "common.h"

class BinaryMatrix {
public:
    int get(int row, int col);

    vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int m = dim[0];
        int n = dim[1];
        int ret = n - 1;

        int i = m - 1, j = n - 1;
        bool found = false;
        while (i >= 0 && j >= 0) {
            int num = binaryMatrix.get(i, j);
            if (num == 0) {
                if (i > 0) --i;
                else break;
            } else {
                ret = std::min(ret, j);
                found = true;
                if (j > 0) --j;
                else --i;
            }
        }

        return found ? ret : -1;
    }
};
