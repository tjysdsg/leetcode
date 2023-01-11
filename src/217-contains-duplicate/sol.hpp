// https://leetcode.cn/problems/contains-duplicate/

#pragma once

#include "common.h"

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> m{};

        for (int n: nums) {
            if (m.find(n) != m.end()) return true;
            m.insert(n);
        }

        return false;
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int> &nums) {
//         std::sort(nums.begin(), nums.end());
//
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             if (nums[i] == nums[i + 1]) return true;
//         }
//
//         return false;
//     }
// };
