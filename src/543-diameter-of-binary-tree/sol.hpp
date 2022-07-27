// https://leetcode.cn/problems/diameter-of-binary-tree/

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

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }

    // returns the max length of any leaf to root
    int dfs(TreeNode *root, int &diameter) {
        if (!root) return -1;

        int left = dfs(root->left, diameter) + 1;
        int right = dfs(root->right, diameter) + 1;
        diameter = std::max(diameter, left + right);
        return std::max(left, right);
    }
};
