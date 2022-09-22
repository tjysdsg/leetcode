// https://leetcode.cn/problems/first-bad-version/

#pragma once

#include "common.h"

class Solution {
public:
    Solution() = delete;

    Solution(int first_bad_version) : first(first_bad_version) {}

    int firstBadVersion(int n) {
        int ret = INT32_MAX;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                ret = std::min(ret, mid);
                right = std::max(left, mid - 1);
            } else {
                left = std::min(right, mid + 1);
            }
        }
        if (isBadVersion(left))
            ret = std::min(ret, left);
        return ret;
    }

    bool isBadVersion(int version) {
        if (version >= first) return true;
        return false;
    }

private:
    int first = 0;
};
