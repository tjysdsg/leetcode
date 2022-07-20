// https://leetcode.cn/problems/search-in-rotated-sorted-array/

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
    int search(vector<int> &nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }

    int binary_search(vector<int> &nums, int i, int j, int target) {
        // base condition
        if (i >= j)
            return nums[i] == target ? i : -1;

        // check midpoint
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;

        // search both left and right parts
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
