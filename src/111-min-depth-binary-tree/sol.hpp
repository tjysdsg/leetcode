// https://leetcode.cn/problems/minimum-depth-of-binary-tree/

#pragma once

#include "common.h"

class Solution {
    int ret = 99999999;

public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        search(root, 1);
        return ret;
    }

    void search(TreeNode *node, int depth) {
        assert(node);
        if (!node->left && !node->right) {
            ret = std::min(ret, depth);
            return;
        }
        if (depth >= ret) return;

        if (node->left)
            search(node->left, depth + 1);
        if (node->right)
            search(node->right, depth + 1);
    }
};
