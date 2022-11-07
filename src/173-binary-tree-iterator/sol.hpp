// https://leetcode.cn/problems/binary-search-tree-iterator/

#pragma once

#include "common.h"

class BSTIterator {
    stack<TreeNode *> s{};
    TreeNode* curr = nullptr;

public:
    BSTIterator(TreeNode *root) : curr(root) {}

    int next() {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        int ret = curr->val;
        curr = curr->right;
        return ret;
    }

    bool hasNext() {
        return !s.empty() || curr;
    }
};
