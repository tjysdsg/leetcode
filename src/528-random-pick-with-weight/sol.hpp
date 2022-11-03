// https://leetcode.cn/problems/random-pick-with-weight/

#pragma once

#include "common.h"
#include <random>

class Solution {
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;
    std::vector<int> prefix_sum{};

public:
    Solution(vector<int> &w) : gen(std::random_device{}()), dis(1, std::accumulate(w.begin(), w.end(), 0)) {
        std::partial_sum(w.begin(), w.end(), std::back_inserter(prefix_sum));
    }

    int pickIndex() {
        int x = dis(gen);
        return std::lower_bound(prefix_sum.begin(), prefix_sum.end(), x) - prefix_sum.begin();
    }
};
