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

// TODO: next_permutation
// TODO: math method

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1; // single digit

        vector<int> digits;

        /// digit -> [indices of numbers greater than digit]
        unordered_map<int, vector<int>> digit2greater_idx{};
        for (int i = 0; i < 10; ++i)
            digit2greater_idx[i] = {};

        // to array of digits
        int idx = 0;
        while (n) {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;

            for (int i = 0; i < digit; ++i)
                digit2greater_idx[i].push_back(idx);

            ++idx;
        }

        // for each digit d, find the lowest digit bd (before d) that is greater than it, and swap(d, bd)
        // then sort all digits below d
        // if the resulting number is within range of int, return it
        // otherwise try the next bd, if still cannot find, try the next d
        size_t n_digits = digits.size();
        for (int i = 1; i < n_digits; ++i) {
            int d = digits[i];

            // greater_idx is sorted
            vector<int> greater_idx = digit2greater_idx[d];
            int swap_i = -1;
            for (int greater_i: greater_idx) {
                if (greater_i >= i) break;

                if (-1 == swap_i || digits[greater_i] < digits[swap_i])
                    swap_i = greater_i;
            }
            if (-1 != swap_i) {
                vector<int> tmp(digits);
                std::swap(tmp[i], tmp[swap_i]);

                // sort the trailing digits to make this number the smallest
                std::sort(tmp.begin(), tmp.begin() + i, std::greater<int>());

                // check if within range of int
                size_t ret = to_int(tmp);
                if (ret <= INT32_MAX)
                    return ret;
            }
        }

        return -1;
    }

    size_t to_int(const vector<int> &digits) {
        size_t ret = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ret = ret * 10 + digits[i];
        }
        return ret;
    }
};
