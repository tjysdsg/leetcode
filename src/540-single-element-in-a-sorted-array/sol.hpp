// https://leetcode.cn/problems/single-element-in-a-sorted-array/

#pragma once

#include "common.h"

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        assert(n % 2 == 1);

        int ret_i = n - 1;
        int i = 0, j = n - 1;
        while (i < j) {
            assert(i % 2 == 0);
            assert(j % 2 == 0);

            int mid = i + (j - i) / 2;
            mid -= mid & 1; // no need to check if mid < i
            assert(mid % 2 == 0);

            assert(mid < n - 1);
            if (nums[mid] != nums[mid + 1]) {
                j = mid;
                ret_i = std::min(ret_i, mid);
            } else {
                i = mid + 2;
            }
        }
        return nums[ret_i];
    }
};

class XOR {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int ret = 0;
        for (int n: nums) {
            ret ^= n;
        }
        return ret;
    }
};
