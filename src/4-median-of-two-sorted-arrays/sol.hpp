// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::vector;

class Solution {
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
    for (int idx = 0; ; ++idx) {
      int num1 = INT_MAX;
      if (p1 < m) num1 = nums1[p1];
      int num2 = INT_MAX;
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
    return 0;
  }
};
