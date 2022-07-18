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
     * Find nums[i] and nums[j], where i < j, nums[i] < nums[j], and they are the rightmost number possible, swap them,
     * and sort the digits after j-th position (to sort we only need to reverse the digit sequence).
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // i not found
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
