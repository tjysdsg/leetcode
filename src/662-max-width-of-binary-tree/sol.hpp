// https://leetcode.cn/problems/maximum-width-of-binary-tree/

#pragma once

#include "common.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        queue<pair<TreeNode *, long long>> q{};
        if (root)
            q.emplace(root, 0);

        long long ret = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int _ = 0; _ < n; ++_) {
                auto curr = q.front();
                q.pop();

                auto *node = curr.first;
                assert(node);
                int i = curr.second;

                if (node->left) {
                    long long new_i = 2LL * i;
                    q.emplace(node->left, new_i);
                }
                if (node->right) {
                    long long new_i = 2LL * i + 1L;
                    q.emplace(node->right, new_i);
                }
            }

            if (!q.empty())
                // start could be > end but that's okay
                ret = std::max(ret, q.back().second - q.front().second + 1);
        }
        return ret;
    }
};
