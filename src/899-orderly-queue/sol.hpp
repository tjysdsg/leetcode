// https://leetcode.cn/problems/orderly-queue/

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
#include <string_view>
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
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            std::string_view ret(s);

            string ds = s + s;
            std::string_view v(ds);

            int n = s.length();
            for (int i = 0; i < n; ++i) {
                ret = std::min(ret, v.substr(i, n));
            }
            return string(ret);
        } else {
            std::sort(s.begin(), s.end());
            return s;
        }
    }
};
