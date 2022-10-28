// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

#pragma once

#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        int i = 1;
        for (int j = 1; j < n; ++j) {
            if (nums[j - 1] != nums[j]) { // same as if (nums[i - 1] != nums[j]) {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};
