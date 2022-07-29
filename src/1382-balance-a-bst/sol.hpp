// https://leetcode.cn/problems/balance-a-binary-search-tree/

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
private:
    vector<TreeNode *> inorder_list{};

public:
    void inorder(TreeNode *o) {
        if (o->left)
            inorder(o->left);

        inorder_list.push_back(o);

        if (o->right)
            inorder(o->right);
    }

    TreeNode *build(int l, int r) {
        int mid = (l + r) / 2;
        TreeNode *o = inorder_list[mid];

        if (l <= mid - 1)
            o->left = build(l, mid - 1);
        else
            o->left = nullptr;

        if (mid + 1 <= r)
            o->right = build(mid + 1, r);
        else
            o->right = nullptr;

        return o;
    }

    TreeNode *balanceBST(TreeNode *root) {
        inorder(root);
        return build(0, inorder_list.size() - 1);
    }
};
