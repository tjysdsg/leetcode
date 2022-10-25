// https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/

#pragma once

#include "common.h"

class Solution {
    vector<int> ans;
    unordered_map<TreeNode *, TreeNode *> parents;

    void find_parents(TreeNode *node) {
        if (!node) return;

        if (node->left) {
            parents[node->left] = node;
            find_parents(node->left);
        }
        if (node->right) {
            parents[node->right] = node;
            find_parents(node->right);
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        // remember all nodes' parents
        find_parents(root);
        // search
        search(target, nullptr, k);
        return ans;
    }

    void search(TreeNode *curr, TreeNode *from, int remain_dist) {
        if (!curr) return;
        if (!remain_dist) {
            ans.push_back(curr->val);
            return;
        }

        if (curr->left != from)
            search(curr->left, curr, remain_dist - 1);
        if (curr->right != from)
            search(curr->right, curr, remain_dist - 1);
        if (parents[curr] != from)
            search(parents[curr], curr, remain_dist - 1);
    }
};
