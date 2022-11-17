// https://leetcode.cn/problems/validate-binary-search-tree/

#pragma once

#include "common.h"


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        assert(root);
        stack<TreeNode *> s{};

        long long prev = INT64_MIN;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();

            if (root->val <= prev) return false;
            prev = root->val;
            root = root->right;
        }

        return true;
    }
};

class Recursion {
public:
    bool isValidBST(TreeNode *root) {
        return is_valid(root, INT64_MIN, INT64_MAX);
    }

    bool is_valid(TreeNode *root, long long low, long long high) {
        if (!root) return true;

        if (root->left && (root->left->val >= root->val || root->left->val <= low)) return false;
        if (root->right && (root->right->val <= root->val || root->right->val >= high)) return false;

        return is_valid(root->left, low, root->val) && is_valid(root->right, root->val, high);
    }
};
