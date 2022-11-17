// https://leetcode.cn/problems/find-duplicate-subtrees/

#pragma once

#include "common.h"

class Solution {
    int guid = 0;
    unordered_map<string, pair<int, TreeNode *>> seen{};
    unordered_set<TreeNode *> res{};

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return vector<TreeNode *>(res.begin(), res.end());
    }

    int dfs(TreeNode *node) {
        if (!node) return -1;

        string serial = std::to_string(node->val) + "," + std::to_string(dfs(node->left)) + "," +
                        std::to_string(dfs(node->right));

        auto it = seen.find(serial);
        if (it != seen.end()) {
            res.insert(it->second.second);
            return it->second.first;
        }

        seen[serial] = {guid, node};
        return guid++;
    }
};
