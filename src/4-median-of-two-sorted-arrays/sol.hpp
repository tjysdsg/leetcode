// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#pragma once

#include "common.h"

class BinarySearch {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // if (m == 0 && n == 0) return 0;
        int target1 = (m + n - 1) / 2;
        int target2 = target1;
        if ((m + n) % 2 == 0) target2 = target1 + 1;

        int p1 = 0, p2 = 0;

        int curr = 0;
        double ret = 0;
        for (int idx = 0;; ++idx) {
            int num1 = INT32_MAX;
            if (p1 < m) num1 = nums1[p1];
            int num2 = INT32_MAX;
            if (p2 < n) num2 = nums2[p2];

            if (num1 < num2) {
                curr = num1;
                ++p1;
            } else {
                curr = num2;
                ++p2;
            }

            if (idx == target1)
                ret += curr;
            if (idx == target2)
                return (ret + curr) / 2;
        }
    }
};

// method 3 in https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
class Partition {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // assume nums1 has less elements
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        int part1_max = 0, part2_min = 0;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int a_part1_max = i == 0 ? INT32_MIN : nums1[i - 1];
            int a_part2_min = i == m ? INT32_MAX : nums1[i];
            int b_part1_max = j == 0 ? INT32_MIN : nums2[j - 1];
            int b_part2_min = j == n ? INT32_MAX : nums2[j];

            if (a_part1_max <= b_part2_min) {
                part1_max = std::max(a_part1_max, b_part1_max);
                part2_min = std::min(a_part2_min, b_part2_min);
                low = i + 1;
                /// continue because we want to find the max i that satisfies the requirement
            } else {
                high = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (part1_max + part2_min) / 2.0 : part1_max;
    }
};
