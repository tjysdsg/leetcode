// https://leetcode.cn/problems/minimum-number-of-days-to-make-m-bouquets/

#pragma once

#include "common.h"

class Solution {
    bool can_make_in_days(const vector<int> &bloom_day, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;
        for (int bd: bloom_day) {
            if (bd <= days) {
                ++flowers;
                if (flowers >= k) {
                    ++bouquets;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }

            if (bouquets >= m) return true;
        }

        return false;
    }

public:
    int minDays(const vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        // if (m * k > n) return -1;  // overflow
        if (m > n / k) return -1;  // overflow

        int l = INT32_MAX;
        int h = INT32_MIN;
        for (int bd: bloomDay) {
            l = std::min(l, bd);
            h = std::max(h, bd);
        }
        assert(l);
        assert(h);

        while (l < h) {
            int mid = l + (h - l) / 2;
            if (can_make_in_days(bloomDay, m, k, mid)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
