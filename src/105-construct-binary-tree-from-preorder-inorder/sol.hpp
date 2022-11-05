// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#pragma once

#include "common.h"

class Iterative {
public:
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        int left_bound = 0;
        stack<TreeNode *> s{};

        auto *root = new TreeNode(preorder[0]);
        s.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            assert(!s.empty());
            auto *node = new TreeNode(preorder[i]);
            if (inorder[left_bound] == s.top()->val) {
                TreeNode* parent = nullptr;
                while (!s.empty() && inorder[left_bound] == s.top()->val) {
                    ++left_bound;
                    parent = s.top();
                    s.pop();
                }
                assert(parent);
                parent->right = node;
            } else {
                s.top()->left = node;
            }
            s.push(node);
        }
        return root;
    }
};

class Recursive {
    unordered_map<int, int> inorder2idx{};

public:
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder2idx[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int pre_i, int pre_j, int in_i, int in_j) {
        if (pre_i > pre_j) return nullptr;
        assert(in_i <= in_j);

        int root_val = preorder[pre_i];
        int root_inorder_idx = inorder2idx[root_val];
        int left_size = root_inorder_idx - in_i;

        auto *node = new TreeNode(root_val);
        node->left = build(preorder, inorder, pre_i + 1, pre_i + left_size, in_i, root_inorder_idx - 1);
        node->right = build(preorder, inorder, pre_i + 1 + left_size, pre_j, root_inorder_idx + 1, in_j);
        return node;
    }
};
