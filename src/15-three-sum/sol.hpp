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
        vector<vector<int>> ret;

        int prev_a = -999999;
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            if (prev_a == a) continue;
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
                    if (a + b + nums[k] < 0) break;
                    if (prev_c != nums[k] && 0 == a + b + nums[k]) {
                        ret.push_back({a, b, nums[k]});
                        prev_c = nums[k];
                        break;
                    }
                    prev_c = nums[k];
                    --k;
                }
            }
        }

        return ret;
    }
};
