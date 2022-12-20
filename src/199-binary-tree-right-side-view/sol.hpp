// https://leetcode.cn/problems/binary-tree-right-side-view/

#pragma once

#include "common.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<pair<TreeNode *, int>> q{};
        unordered_map<int, int> level2node{};

        q.emplace(root, 1);
        int max_level = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            auto *node = p.first;
            int level = p.second;

            if (!node) continue;

            max_level = std::max(max_level, level);
            if (level2node.find(level) == level2node.end()) {
                level2node[level] = node->val;
            }

            q.emplace(node->right, level + 1);
            q.emplace(node->left, level + 1);
        }

        vector<int> ret(max_level, 0);
        for (int i = 1; i <= max_level; ++i) {
            ret[i - 1] = level2node[i];
        }
        return ret;
    }
};
