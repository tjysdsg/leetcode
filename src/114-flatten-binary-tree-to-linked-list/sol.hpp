// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/

#pragma once

#include "common.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root) {
            auto *fake_head = new TreeNode(-1, nullptr, nullptr);
            iterate(root, fake_head);
        }
    }

    void iterate(TreeNode *node, TreeNode *&curr) {
        TreeNode *left = node->left;
        TreeNode *right = node->right;

        curr->right = node;
        curr = curr->right;

        node->left = nullptr;
        node->right = nullptr;

        if (left) {
            iterate(left, curr);
        }
        if (right) {
            iterate(right, curr);
        }
    }
};
