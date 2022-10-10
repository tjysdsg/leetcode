// https://leetcode.cn/problems/product-of-array-except-self/

#pragma once

#include "common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> ret(n, 1);

        int prefix = nums[0];
        int suffix = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            ret[i] *= prefix;
            prefix *= nums[i];

            ret[n - 1 - i] *= suffix;
            suffix *= nums[n - 1 - i];
        }

        return ret;
    }
};
