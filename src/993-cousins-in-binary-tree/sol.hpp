// https://leetcode.cn/problems/cousins-in-binary-tree/

#pragma once

#include "common.h"

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        queue<pair<TreeNode *, TreeNode *>> q{};
        assert(root);
        q.emplace(root, nullptr);

        TreeNode *px = nullptr, *py = nullptr;
        while (!q.empty()) {
            int n = q.size();
            for (int _ = 0; _ < n; ++_) {
                auto p = q.front();
                auto *node = p.first;
                auto *parent = p.second;
                assert(node);
                q.pop();

                if (node->val == x) {
                    px = parent;
                } else if (node->val == y) {
                    py = parent;
                }

                if (node->left) q.emplace(node->left, node);
                if (node->right) q.emplace(node->right, node);
            }

            if (px && py) {
                if (px != py) return true;
                else return false;
            } else if (px || py) return false;
        }

        return false;
    }
};
