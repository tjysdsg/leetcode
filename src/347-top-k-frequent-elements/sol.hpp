// https://leetcode.cn/problems/top-k-frequent-elements/

#pragma once

#include "common.h"

// TODO: quicksort

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> m{};
        for (int n: nums) {
            ++m[n];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>> /* , std::greater<pair<int, int>> */> q{};
        for (const auto &it: m) {
            q.emplace(it.second, it.first);
        }

        vector<int> ret{};
        while (ret.size() < k) {
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
};
