// https://leetcode.cn/problems/boundary-of-binary-tree/

#pragma once

#include "common.h"

class Solution {
    vector<int> left_boundary{};
    vector<int> right_boundary{};
    vector<int> leaves{};

    enum TYPE {
        ROOT,
        LEFT_BOUNDARY,
        RIGHT_BOUNDARY,
        LEAVES,
        OTHER,
    };

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        preorder(root, ROOT);

        left_boundary.insert(left_boundary.end(), leaves.begin(), leaves.end());
        left_boundary.insert(left_boundary.end(), right_boundary.rbegin(), right_boundary.rend());
        return left_boundary;
    }

    void preorder(TreeNode *node, TYPE node_type) {
        assert(node);

        switch (node_type) {
            case ROOT:
                left_boundary.push_back(node->val);
                break;
            case LEFT_BOUNDARY:
                left_boundary.push_back(node->val);
                break;
            case RIGHT_BOUNDARY:
                right_boundary.push_back(node->val);
                break;
            case LEAVES:
                leaves.push_back(node->val);
                break;
            default:
                break;
        }
        if (node->left)
            preorder(node->left, get_left_child_type(node, node_type));
        if (node->right)
            preorder(node->right, get_right_child_type(node, node_type));
    }

    TYPE get_left_child_type(TreeNode *parent, TYPE parent_type) {
        assert(parent_type != LEAVES);
        if (!parent->left->left && !parent->left->right)
            return LEAVES;

        switch (parent_type) {
            case ROOT:
                return LEFT_BOUNDARY;
            case LEFT_BOUNDARY:
                return LEFT_BOUNDARY;
            case RIGHT_BOUNDARY:
                return parent->right ? OTHER : RIGHT_BOUNDARY;
            default:
                break;
        }
        return OTHER;
    }

    TYPE get_right_child_type(TreeNode *parent, TYPE parent_type) {
        assert(parent_type != LEAVES);
        if (!parent->right->left && !parent->right->right)
            return LEAVES;

        switch (parent_type) {
            case ROOT:
                return RIGHT_BOUNDARY;
            case LEFT_BOUNDARY:
                return parent->left ? OTHER : LEFT_BOUNDARY;
            case RIGHT_BOUNDARY:
                return RIGHT_BOUNDARY;
            default:
                break;
        }
        return OTHER;
    }
};
