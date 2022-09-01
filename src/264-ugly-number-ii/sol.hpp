// https://leetcode.cn/problems/ugly-number-ii/

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
#include <unordered_set>
#include <queue>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::set;
using std::stack;

class MinHeap {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        std::priority_queue<long, vector<long>, std::greater<long>> min_heap;
        unordered_set<long> uglies;

        min_heap.push(1);
        uglies.insert(1);
        int ret = 1;
        for (int i = 0; i < n; ++i) {
            long val = min_heap.top();
            min_heap.pop();
            ret = val;

            for (int f: factors) {
                long next = f * val;
                if (uglies.find(next) == uglies.end()) {
                    min_heap.push(next);
                    uglies.insert(next);
                }
            }
        }

        return ret;
    }
};

class DP {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0); // dp[i] = the (i+1)-th ugly number

        dp[0] = 1;

        int mul_by_2_idx = 0;
        int mul_by_3_idx = 0;
        int mul_by_5_idx = 0;

        for (int i = 1; i < n; ++i) {
            int by2 = dp[mul_by_2_idx] * 2;
            int by3 = dp[mul_by_3_idx] * 3;
            int by5 = dp[mul_by_5_idx] * 5;

            int ugly = std::min(by2, std::min(by3, by5));
            dp[i] = ugly;
            if (by2 == ugly)
                ++mul_by_2_idx;
            if (by3 == ugly)
                ++mul_by_3_idx;
            if (by5 == ugly)
                ++mul_by_5_idx;
        }

        return dp[n - 1];
    }
};
