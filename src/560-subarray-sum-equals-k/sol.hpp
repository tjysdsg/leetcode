// https://leetcode.cn/problems/subarray-sum-equals-k/

#pragma once

#include <numeric>
#include "common.h"

class Solution {
    unordered_map<int, int> map{}; // prefix_sum -> frequency
public:
    int subarraySum(const vector<int> &nums, int k) {
        int n = nums.size();
        assert(n);
        int ret = 0;

        map[0] = 1;
        int sum = 0;
        for (int i: nums) {
            sum += i;

            // sum[j] - sum[i] = k (j > i), curr sum is the j-th
            auto it = map.find(sum - k);
            if (it != map.end()) {
                ret += it->second;
            }
            ++map[sum];
        }

        return ret;
    }
};
