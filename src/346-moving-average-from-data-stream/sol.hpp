// https://leetcode.cn/problems/moving-average-from-data-stream/

#pragma once

#include <numeric>
#include "common.h"

class Solution {
private:
    vector<int> nums;
    int max_size = 0;
    int sum = 0;
    int n = 0;

public:
    Solution(int size) : max_size(size), nums(size, 0) {}

    double next(int val) {
        ++n;
        int idx = n % max_size;

        sum += val - nums[idx];
        nums[idx] = val;

        return (double) sum / std::min((int) nums.size(), n);
    }
};
