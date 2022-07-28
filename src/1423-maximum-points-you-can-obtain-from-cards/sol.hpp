// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

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

class Solution {
public:
    int maxScore(vector<int> &nums, int k) {
        int n = nums.size();
        int ret = 0;

        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        ret = sum;

        //              <---- move window <----
        // | k-i-1 elements |      ...       | i+1 elements |
        for (int i = 0; i < k; ++i) {
            sum += nums[n - i - 1];
            sum -= nums[k - i - 1];
            ret = std::max(sum, ret);
        }

        return ret;
    }
};
