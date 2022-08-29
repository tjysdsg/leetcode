// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

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
#include <queue>
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int ret = nums[0];
        search(nums, 0, nums.size() - 1, ret);
        return ret;
    }

    void search(vector<int> &nums, int l, int r, int &ans) {
        if (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                search(nums, mid + 1, r, ans);
            } else {
                search(nums, l, mid, ans);
            }
        } else if (l == r) {
            ans = nums[l];
        }
    }
};
