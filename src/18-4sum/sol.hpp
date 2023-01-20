// https://leetcode.cn/problems/4sum/

#pragma once

#include "common.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ret{};
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if ((long) nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] <
                target)
                continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if ((long) nums[i] + nums[j] + nums[n - 1] + nums[n - 2] <
                    target)
                    continue;

                int p = j + 1;
                int k = n - 1;

                while (p < k) {
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[p];
                    int d = nums[k];
                    long sum = (long) a + b + c + d;
                    if (sum == target) {
                        ret.push_back({a, b, c, d});
                        ++p;
                        while (p < k && nums[p - 1] == nums[p])
                            ++p;
                        --k;
                        while (p < k && nums[k] == nums[k + 1])
                            --k;
                    } else if (sum > target) {
                        --k;
                    } else {
                        ++p;
                    }
                }
            }
        }

        return ret;
    }
};
