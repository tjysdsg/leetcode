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

        int prev_a = -999999;
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            if (prev_a == a) continue; // in case nums = {0, 0, ..., 0}
            prev_a = a;

            int prev_b = -999999;
            int prev_c = -999999;
            int k = n - 1;
            for (int j = i + 1; j < n - 1; ++j) {
                if (j >= k) break;

                int b = nums[j];
                if (prev_b == b) continue;
                prev_b = b;

                while (j < k) {
                    int c = nums[k];
                    if (a + b + c < 0) break;
                    if (prev_c != c && 0 == a + b + c) {
                        ret.push_back({a, b, c});
                        prev_c = c;
                        break;
                    }
                    prev_c = c;
                    --k;
                }
            }
        }

        return ret;
    }
};
