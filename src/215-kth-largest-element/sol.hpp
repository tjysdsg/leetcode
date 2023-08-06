// https://leetcode.cn/problems/kth-largest-element-in-an-array

#pragma once

#include "common.h"

class Solution {
public:
    // modified quicksort
    // descending
    // only sorts that parts that contains k-th element
    int partial_sort(vector<int> &nums, int l, int r, int k) {
        int pivot = 0;
        if (l >= 0 && r >= 0 && l < r)
            pivot = partition(nums, l, r);

        if (pivot == k || (l == r && l == k))
            return nums[k];

        if (pivot < k)
            return partial_sort(nums, pivot + 1, r, k);
        else
            return partial_sort(nums, l, pivot - 1, k);
    }

    int partition(vector<int> &nums, int l, int r) {
        int p = nums[(l + r) / 2];
        while (true) {
            while (nums[l] > p)
                ++l;
            while (nums[r] < p)
                --r;

            if (l != r && nums[l] == nums[r]) { // = in case something like 4 2 3 4 1 7 4 where pivot value is 4
                --r;
            }

            if (l >= r) return l;

            std::swap(nums[l], nums[r]);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        return partial_sort(nums, 0, nums.size() - 1, k - 1);
    }
};
