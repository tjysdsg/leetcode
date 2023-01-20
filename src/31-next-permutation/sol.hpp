// https://leetcode.cn/problems/next-permutation/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

class Solution {
public:
    /**
     * 1. Find the largest i and j such that i < j and nums[i] < nums[j]
     * 2. Swap them (thus making the entire number bigger)
     * 3. Sort the digits after j-th position (equivalent to reversing the digit subsequence,
     *    because we've already checked that any subsequence after j-th position is not increasing)
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        /// special case: i not found, just reverse the sequence and return
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
