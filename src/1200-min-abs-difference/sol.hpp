// https://leetcode.cn/problems/minimum-absolute-difference/

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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        std::sort(arr.begin(), arr.end());

        size_t n = arr.size();
        int i = 0;
        int j = 1;
        vector<vector<int>> ret{};
        int min_diff = INT32_MAX;
        while (j < n) {
            int diff = std::abs(arr[j] - arr[i]);
            if (diff <= min_diff) {
                if (diff < min_diff)
                    ret.clear();
                ret.push_back({arr[i], arr[j]});
                min_diff = diff;
            }

            ++i;
            ++j;
        }

        return ret;
    }
};
