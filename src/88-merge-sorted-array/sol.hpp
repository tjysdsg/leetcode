// https://leetcode.cn/problems/merge-sorted-array/

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

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0)
                nums1[k--] = nums2[j--];
            else if (j < 0)
                nums1[k--] = nums1[i--];
            else {
                if (nums1[i] <= nums2[j])
                    nums1[k--] = nums2[j--];
                else
                    nums1[k--] = nums1[i--];
            }
        }
    }
};
