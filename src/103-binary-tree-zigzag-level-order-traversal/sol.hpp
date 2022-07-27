// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

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

/*

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> ret{};
        std::deque<TreeNode *> q{};

        q.push_back(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();

            vector<int> v;
            v.reserve(n);

            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front();
                assert(t);
                q.pop_front();
                v.push_back(t->val);
                if (t->left)
                    q.push_back(t->left);
                if (t->right)
                    q.push_back(t->right);
            }

            // TODO: or use std::dequeue<int> v;
            if (level % 2) std::reverse(v.begin(), v.end());
            ret.push_back(v);
            ++level;
        }
        return ret;
    }
};

*/

class Solution {
public:
    /// TRUE zigzag TRAVERSING order
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> ret{};
        vector<TreeNode *> q1{};
        vector<TreeNode *> q2{};

        q1.push_back(root);
        while (!q1.empty()) {
            int n = q1.size();

            vector<int> v;
            v.reserve(n);

            for (int i = 0; i < n; ++i) {
                TreeNode *t = q1.back();
                assert(t);
                q1.pop_back();
                v.push_back(t->val);

                if (ret.size() % 2) {
                    if (t->right)
                        q2.push_back(t->right);
                    if (t->left)
                        q2.push_back(t->left);
                } else {
                    if (t->left)
                        q2.push_back(t->left);
                    if (t->right)
                        q2.push_back(t->right);
                }
            }

            q1.swap(q2);
            q2.clear();
            ret.push_back(v);
        }
        return ret;
    }
};
