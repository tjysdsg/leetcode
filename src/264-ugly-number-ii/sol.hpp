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
