// https://leetcode.cn/problems/container-with-most-water/

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
    int maxArea(vector<int> &height) {
        size_t n = height.size();

        if (n <= 1) return 0;

        int i = 0, j = n - 1;
        int ret = 0;
        while (i < j) {
            int shorter = std::min(height[i], height[j]);
            ret = std::max(shorter * (j - i), ret);

            if (height[i] < height[j])
                ++i;
            else
                --j;
        }

        return ret;
    }
};
