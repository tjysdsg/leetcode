// https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

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

class RBTree {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        std::multiset<int> s;
        int ret = 0;
        while (r < n) {
            s.insert(nums[r]);
            if (std::abs(*s.begin() - *s.rbegin()) > limit) {
                s.erase(s.find(nums[l++]));
            }
            ret = std::max(ret, r - l + 1);
            ++r;
        }
        return ret;
    }
};

class MonoQueue {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        std::deque<int> minq; // front is min
        std::deque<int> maxq; // front is max

        int ret = 0;
        while (r < n) {
            // insert max queue
            while (!maxq.empty() && maxq.back() < nums[r]) {
                maxq.pop_back();
            }
            maxq.push_back(nums[r]);

            // insert min queue
            while (!minq.empty() && minq.back() > nums[r]) {
                minq.pop_back();
            }
            minq.push_back(nums[r]);

            // move left right if over limit
            while (!maxq.empty() && !minq.empty() && maxq.front() - minq.front() > limit) {
                if (maxq.front() == nums[l])
                    maxq.pop_front();
                if (minq.front() == nums[l])
                    minq.pop_front();
                ++l;
            }
            ret = std::max(ret, r - l + 1);
            ++r;
        }
        return ret;
    }
};
