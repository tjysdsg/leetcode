// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#pragma once

#include "common.h"

class Solution {
    unordered_map<int, int> postorder2idx{};

public:
    TreeNode *constructFromPrePost(const vector<int> &preorder, const vector<int> &postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            postorder2idx[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(const vector<int> &preorder, const vector<int> &postorder,
                    int pre_i, int pre_j, int post_i, int post_j) {
        if (post_i > post_j) return nullptr;
        assert(pre_i <= pre_j);

        int val = preorder[pre_i];
        auto *node = new TreeNode(val);
        if (pre_i == pre_j) return node;

        int pre_left = pre_i + 1;
        int post_left = postorder2idx[preorder[pre_left]];
        int right_size = post_j - 1 - post_left;
        // | root | left | right |
        // | left | right | root |

        node->left = build(preorder, postorder, pre_left, pre_j - right_size, post_i, post_j - 1 - right_size);
        node->right = build(preorder, postorder, pre_j - right_size + 1, pre_j, post_j - right_size, post_j - 1);
        return node;
    }
};
