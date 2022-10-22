// https://leetcode.cn/problems/next-greater-element-iii/

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

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

// TODO: math method

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1; // single digit

        string digits = std::to_string(n);

        // see LeetCode 31. Next Permutation
        n = digits.size();
        int i = n - 2;
        while (i >= 0 && digits[i] >= digits[i + 1])
            --i;

        if (i < 0) return -1;

        int j = n - 1;
        while (j > i && digits[i] >= digits[j])
            --j;

        std::swap(digits[i], digits[j]);
        std::reverse(digits.begin() + i + 1, digits.end());

        size_t ret = std::stol(digits);
        return ret > INT32_MAX ? -1 : ret;
    }
};
