// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#pragma once

#include "common.h"

// TODO
class Iterative {
public:
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        return nullptr;
    }
};

class Recursive {
    unordered_map<int, int> inorder2idx{};

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inorder2idx[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder,
                    int in_i, int in_j, int post_i, int post_j) {
        if (post_i > post_j) return nullptr;
        assert(in_i <= in_j);

        int val = postorder[post_j];
        auto *node = new TreeNode(val);
        int in_idx = inorder2idx[val];
        int left_size = in_idx - in_i;

        node->left = build(inorder, postorder, in_i, in_i + left_size - 1, post_i, post_i + left_size - 1);
        node->right = build(inorder, postorder, in_i + left_size + 1, in_j, post_i + left_size, post_j - 1);
        return node;
    }
};
