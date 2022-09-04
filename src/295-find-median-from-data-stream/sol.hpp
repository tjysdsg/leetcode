// https://leetcode.cn/problems/find-median-from-data-stream/

#pragma once

#include "common.h"

// TODO: sorted set + double pointers
// TODO: followup question 1&2

class MedianFinder {
private:
    priority_queue<int> lower{};
    priority_queue<int, vector<int>, std::greater<int>> upper{};

public:
    MedianFinder() {}

    void addNum(int num) {
        int left = INT32_MAX;
        if (!lower.empty()) {
            left = lower.top();
        }

        if (num < left) {
            lower.push(num);
        } else {
            upper.push(num);
        }

        size_t l = lower.size();
        size_t u = upper.size();
        if (l + 1 < u) {
            lower.push(upper.top());
            upper.pop();
        } else if (u + 1 < l) {
            upper.push(lower.top());
            lower.pop();
        }
    }

    double findMedian() {
        size_t l = lower.size();
        size_t u = upper.size();

        if (l == u) {
            return (double) (lower.top() + upper.top()) / 2;
        } else if (l < u) {
            return upper.top();
        } else {
            return lower.top();
        }
    }
};
