// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-ii/

#pragma once

#include "common.h"

class Solution {
    TreeNode *_p = nullptr;
    TreeNode *_q = nullptr;
    TreeNode *ret = nullptr;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        _p = p;
        _q = q;
        int s = dfs(root);
        if (s != 3) return nullptr;
        return ret;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;

        // enum STATUS {
        //     NONE = 0,
        //     FOUND_P = 1,
        //     FOUND_Q = 2,
        //     FOUND_BOTH = 3, // = FOUND_P | FOUND_Q
        // };

        int s = 0;
        if (node == _p) s |= 1;
        else if (node == _q) s |= 2;

        int s1 = dfs(node->left);
        if (s1 == 3) return s1; // early return if already found an answer in the subtree

        // early return if current node is confirmed to be LCA
        s |= s1;
        if (s == 3 && !ret) {
            ret = node;
            return s;
        }

        s |= dfs(node->right);
        if (s == 3 && !ret) ret = node;
        return s;
    }
};
