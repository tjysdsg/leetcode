// https://leetcode.cn/problems/next-permutation/

#pragma once

#include "common.h"

class Solution {
public:
    /**
     * 1. Find the largest i such that elements after i are decreasing
     * 2. Find the largest j such that i < j and nums[i] < nums[j]
     * 3. Swap them.
     *    - If i doesn't conform the condition from step 1,
     *      the resulting sequence has already occurred in the previous permutation.
     *    - If j is not the largest j, we risk skipping the next permutation.
     * 4. Sort the digits after j-th position.
     *    This leads to a min value that is larger than the previous permutation.
     *    This is equivalent to reversing the digit subsequence
     *    because according step 1 and 2 all elements after j-th position are not increasing
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // special case: i not found, just reverse the sequence and return
        if (i < 0 || nums[i] >= nums[i + 1]) {
            reverse(nums, 0, n - 1);
            return;
        }

        int j = n - 1;
        while (j > i && nums[i] >= nums[j]) {
            --j;
        }

        std::swap(nums[i], nums[j]);
        reverse(nums, i + 1, n - 1);
    }

    void reverse(vector<int> &nums, int i, int j) {
        while (i < j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
};
