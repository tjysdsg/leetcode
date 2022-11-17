// https://leetcode.cn/problems/path-sum/

#pragma once

#include "common.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;

        queue<pair<TreeNode *, int>> q{};
        q.emplace(root, targetSum);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            auto *node = p.first;
            int remain = p.second - node->val;
            if (remain == 0 && !node->left && !node->right) return true;

            if (node->left) q.emplace(node->left, remain);
            if (node->right) q.emplace(node->right, remain);
        }

        return false;
    }
};
