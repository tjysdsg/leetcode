// https://leetcode.cn/problems/search-in-rotated-sorted-array/

#pragma once

#include "common.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }

    int binary_search(vector<int> &nums, int i, int j, int target) {
        if (i >= j)
            return nums[i] == target ? i : -1;

        // check midpoint
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;

        int r = std::max(i, mid - 1);
        int l = std::min(mid + 1, j);

        if (nums[i] <= nums[r]) { // [i, r] does not contain rotate pivot
            if (target >= nums[i] && target <= nums[r])
                return binary_search(nums, i, r, target);
            else
                return binary_search(nums, l, j, target);
        } else { // [l, j] does not contain rotate pivot
            if (target >= nums[l] && target <= nums[j])
                return binary_search(nums, l, j, target);
            else
                return binary_search(nums, i, r, target);
        }
    }
};
