// https://leetcode.cn/problems/single-element-in-a-sorted-array/

#pragma once

#include "common.h"

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int ret = 0;
        for (int n: nums) {
            ret ^= n;
        }
        return ret;
    }
};
