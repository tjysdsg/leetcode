// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <queue>
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) std::swap(p, q);

        TreeNode *ret = root;
        while (true) {
            if (p->val < ret->val && q->val < ret->val)
                ret = ret->left;
            else if (p->val > ret->val && q->val > ret->val)
                ret = ret->right;
            else
                return ret;
        }
    }
};

/**
 * General solution for binary tree
 */
/*

class Solution {
private:
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;
    TreeNode *res = nullptr;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *_p, TreeNode *_q) {
        p = _p;
        q = _q;
        dfs(root);
        return res;
    }

    // 1 = 0b01: p found, 2 = 0b10: q found, 3: both found
    int dfs(TreeNode *node) {
        assert(!(node == p && node == q));
        int ret = 0;

        if (node == p)
            ret |= 1;
        else if (node == q)
            ret |= 2;

        ret |= node->left ? dfs(node->left) : 0;
        ret |= node->right ? dfs(node->right) : 0;

        if (!res && 3 == ret)
            res = node;

        return ret;
    }
};

*/