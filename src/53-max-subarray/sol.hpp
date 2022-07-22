// https://leetcode.cn/problems/maximum-subarray/

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

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class NB {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();

        int ret = INT32_MIN;
        int curr_sum = 0;
        for (int i = 0; i < n; ++i) {
            curr_sum += nums[i];

            // this must be before the if statement below, for situations like nums = {-1, -2, -3}
            ret = std::max(ret, curr_sum);

            // equivalent to skipping nums[0..i] where sum(nums[0..i]) < 0 causes the overall sum to be smaller
            if (curr_sum < 0) curr_sum = 0;

        }

        return ret;
    }
};

class DP {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();

        // dp[i] = max subarray in [0, i] that ends with nums[i]
        // dp[i] = max(dp[i-1] + nums[i], nums[i])
        vector<int> dp(n, 0);

        int ret = dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};

struct Sum {
    Sum(int l_sum, int r_sum, int s_sum, int sum) : l_sum(l_sum), r_sum(r_sum), s_sum(s_sum), sum(sum) {}

    int l_sum = 0; // max subarray sum starting at the first element
    int r_sum = 0; // max subarray sum ending at the last element
    int s_sum = 0; // max subarray sum
    int sum = 0; // total sum
};

class DivideConquer {
public:
    int maxSubArray(const vector<int> &nums) {
        int n = nums.size();
        return divide_merge(nums, 0, n - 1).s_sum;
    }

    // returns the max subarray sum in [i, j]
    Sum divide_merge(const vector<int> &nums, int i, int j) {
        if (i >= j)
            return {nums[i], nums[i], nums[i], nums[i]};

        int m = (i + j) / 2;
        Sum left = divide_merge(nums, i, m);
        Sum right = divide_merge(nums, std::min(m + 1, j), j);

        int sum = left.sum + right.sum;
        int l_sum = std::max(left.sum + right.l_sum, left.l_sum);
        int r_sum = std::max(left.r_sum + right.sum, right.r_sum);

        int s_sum = std::max(std::max(left.s_sum, right.s_sum), left.r_sum + right.l_sum);
        return {l_sum, r_sum, s_sum, sum};
    }
};
