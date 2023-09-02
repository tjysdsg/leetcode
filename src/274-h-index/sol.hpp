// https://leetcode.cn/problems/h-index/

#pragma once

#include "common.h"

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int h = 0;
        std::sort(citations.begin(), citations.end(), std::greater());
        for (int i: citations) {
            if (i > h) {
                ++h;
            }
        }

        return h;
    }
};
