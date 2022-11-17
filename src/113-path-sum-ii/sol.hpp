// https://leetcode.cn/problems/path-sum-ii/

#pragma once

#include "common.h"


class Solution {
    vector<vector<int>> res{};
    vector<int> path{};

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (!root) return {};
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode *node, int remain) {
        assert(node);

        remain -= node->val;
        path.push_back(node->val);

        if (remain == 0 && !node->left && !node->right) {
            res.push_back(path);
            path.pop_back();
            return;
        }

        if (node->left) dfs(node->left, remain);
        if (node->right) dfs(node->right, remain);

        path.pop_back();
    }
};
