// https://leetcode.cn/problems/maximum-binary-tree/

#pragma once

#include "common.h"

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        stack<TreeNode *> s{};

        TreeNode *ret = nullptr;
        for (int i: nums) {
            auto *node = new TreeNode(i);
            if (s.empty()) {
                ret = node;
            }

            while (!s.empty() && s.top()->val < i) {
                node->left = s.top();
                s.pop();
            }
            if (!s.empty())
                s.top()->right = node;
            else
                ret = node;

            s.push(node);
        }

        return ret;
    }
};

class Recursion {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(const vector<int> &nums, int i, int j) {
        if (i == j) return new TreeNode(nums[i]);

        int max_i = i;
        int max_num = INT32_MIN;
        for (int idx = i; idx <= j; ++idx) {
            if (nums[idx] > max_num) {
                max_i = idx;
                max_num = nums[idx];
            }
        }

        auto *ret = new TreeNode(max_num);
        if (i < max_i) {
            ret->left = build(nums, i, max_i - 1);
        }
        if (max_i < j) {
            ret->right = build(nums, max_i + 1, j);
        }

        return ret;
    }
};
