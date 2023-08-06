// https://leetcode-cn.com/problems/3sum/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::set;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        if (nums[0] > 0 || nums[n - 1] < 0) return {};
        vector<vector<int>> ret;

        // a = nums[i], b = nums[j], c = nums[k]
        // a < b < c

        for (int i = 0; i < n - 2;) {
            int a = nums[i];

            // use double pointers to find b and c
            int j = i + 1;
            int k = n - 1;
            int prev;
            while (j < k) {
                int b = nums[j];
                int c = nums[k];

                if (a + b + c == 0) {
                    ret.push_back({a, b, c});

                    // move left pointer to right
                    prev = nums[j];
                    while (j < k && prev == nums[j]) ++j;
                    // move right pointer to left
                    prev = nums[k];
                    while (j < k && prev == nums[k]) --k;
                } else if (a + b + c < 0) { // move left pointer to right
                    prev = nums[j];
                    while (j < k && prev == nums[j]) ++j;
                } else { // move right pointer left
                    prev = nums[k];
                    while (j < k && prev == nums[k]) --k;
                }
            }

            prev = nums[i];
            while (i < n && prev == nums[i]) ++i;
        }

        return ret;
    }
};
