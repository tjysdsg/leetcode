// https://leetcode.cn/problems/missing-number/

#pragma once

#include <numeric>
#include "common.h"

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
};

class Math {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return n * (n + 1) / 2 - sum;
    }
};
