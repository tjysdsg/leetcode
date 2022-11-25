// https://leetcode.cn/problems/binary-tree-maximum-path-sum/

#pragma once

#include "common.h"

class Solution {
    int res = INT32_MIN;
public:
    int maxPathSum(TreeNode *root) {
        max_sum(root);
        return res;
    }

    int max_sum(TreeNode *node) {
        if (!node) return 0;

        int left_max = std::max(max_sum(node->left), 0);
        int right_max = std::max(max_sum(node->right), 0);
        res = std::max(res, left_max + right_max + node->val);

        return node->val + std::max(left_max, right_max);
    }
};
