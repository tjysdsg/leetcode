// https://leetcode.cn/problems/longest-consecutive-sequence/

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
#include <unordered_set>
#include <queue>
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int ret = 0;
        std::unordered_set<int> s;
        for (const int &n: nums) {
            s.insert(n);
        }

        for (const int &n: nums) {
            if (s.find(n - 1) == s.end()) {
                int i;
                for (i = n + 1; s.find(i) != s.end(); ++i) {
                }
                ret = std::max(ret, i - n);
            }
        }

        return ret;
    }
};
