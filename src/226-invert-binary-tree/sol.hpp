// https://leetcode.cn/problems/invert-binary-tree/

#pragma once

#include "common.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        queue<TreeNode *> q{};
        q.push(root);

        while (!q.empty()) {
            auto *node = q.front();
            q.pop();

            if (!node) continue;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            std::swap(node->left, node->right);
        }

        return root;
    }
};
