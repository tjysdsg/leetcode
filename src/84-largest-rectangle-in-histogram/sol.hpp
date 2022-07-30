// https://leetcode.cn/problems/largest-rectangle-in-histogram/

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
    int largestRectangleArea(vector<int> &h) {
        stack<int> max_stack; // monotone-increase stack

        int ret = 0;
        int n = h.size();
        /*
         * For each bar, find the widest rectangle with its height
         */
        for (int i = 0; i <= n; ++i) {
            int hi = i != n ? h[i] : INT32_MIN;

            // the bar itself
            ret = std::max(ret, hi);

            /*
             * Let j be the stack top.
             *
             * h[i] is the height of the widest rectangle we are searching.
             *
             * In this while loop, h[j] >= h[i], meaning that i is definitely the right boundary (exclusive)
             * of the rectangle.
             * Then we only need to find the left boundary.
             *
             * Let k be the previous stack top, then the left boundary (inclusive) is (k+1)
             */
            while (!max_stack.empty()) {
                int top = max_stack.top();
                if (h[top] < hi)
                    break;
                max_stack.pop();

                int k = max_stack.empty() ? -1 : max_stack.top();
                ret = std::max(ret, h[top] * (i - k - 1));
            }
            max_stack.push(i);
        }

        return ret;
    }
};
