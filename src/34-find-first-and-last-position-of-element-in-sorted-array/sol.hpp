// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

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
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ret{-1, -1};
        search(nums, 0, nums.size() - 1, target, ret);

        if (ret[0] != -1 && nums[ret[0]] != target)
            ret[0] = -1;
        if (ret[1] != -1 && nums[ret[1]] != target)
            ret[1] = -1;
        return ret;
    }

    void search(vector<int> &nums, int l, int r, int target, vector<int> &ans) {
        int n = nums.size();
        if (l == r && nums[l] == target) {
            ans[0] = std::min((unsigned) ans[0], (unsigned) l);
            ans[1] = std::max(ans[1], l);
        } else if (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] == target)
                    search(nums, l, mid - 1, target, ans);
                else
                    ans[0] = mid;

                if (mid + 1 < n && nums[mid + 1] == target)
                    search(nums, mid + 1, r, target, ans);
                else
                    ans[1] = mid;
            } else if (nums[mid] < target) {
                ans[0] = mid + 1;
                search(nums, mid + 1, r, target, ans);
            } else {
                ans[1] = mid - 1;
                search(nums, l, mid - 1, target, ans);
            }
        }
    }
};
