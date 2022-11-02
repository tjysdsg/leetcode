// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/

#pragma once

#include "common.h"

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return root;

        iterate(root->left, root->right);
        return root;
    }

    void iterate(Node *a, Node *b) {
        if (!a) return;

        a->next = b;

        iterate(a->left, a->right);
        iterate(a->right, b->left);
        iterate(b->left, b->right);
    }
};
