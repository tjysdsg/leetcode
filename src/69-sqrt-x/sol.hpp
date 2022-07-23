// https://leetcode.cn/problems/sqrtx/

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
    int mySqrt(int x) {
        return search(x, 0, x);
    }

    int search(int x, int i, int j) {
        int m = (i + j) / 2;
        long m2 = (long) m * (long) m;
        if (m2 <= x && (long) (m + 1) * (long) (m + 1) > x) {
            return m;
        }

        if (m2 < x)
            return search(x, std::min(j, m + 1), j);
        else
            return search(x, i, std::max(i, m - 1));
    }
};
