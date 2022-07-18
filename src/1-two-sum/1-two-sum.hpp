// https://leetcode-cn.com/problems/two-sum/

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::cout;
using std::vector;

class Unoptimized {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int N = nums.size();

        std::map<int, int> val2idx; // maps values in nums to their indices
        for (int i = 0; i < N; ++i) { // init val2idx
            val2idx[nums[i]] = i;
        }

        for (int idx0 = 0; idx0 < N; ++idx0) {
            int sub = (int) target - (int) nums[idx0];
            const auto q = val2idx.find(sub);
            if (q != val2idx.end() && idx0 != q->second) {
                return {idx0, q->second};
            }
        }

        return {};
    }
};

// no need to loop twice
class Optimized {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int N = nums.size();

        std::map<int, int> val2idx;
        for (int i = 0; i < N; ++i) {
            int sub = (int) target - (int) nums[i];
            const auto &q = val2idx.find(sub);
            if (q != val2idx.end()) {
                // if (i != q->second) // no need to check since the current element is not even in val2idx yet
                return {i, q->second};
            }
            // since no requirements on the order of result, we can set val2idx as we go
            val2idx[nums[i]] = i;
        }

        return {};
    }
};
