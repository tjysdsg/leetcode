// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/

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

// TODO: iterative
// TODO: self-balancing tree

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        TreeNode *ret = nullptr;
        search(root, k, count, ret);
        assert(ret);
        return ret->val;
    }

    void search(TreeNode *node, int k, int &count, TreeNode *&res) {
        assert(node);

        if (node->left)
            search(node->left, k, count, res);

        ++count;
        if (count == k) {
            res = node;
        } else if (count < k && node->right) {
            search(node->right, k, count, res);
        }
    }
};
