// https://leetcode.cn/problems/binary-tree-level-order-traversal/

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
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

class Recursive {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret{};
        bfs(ret, root, 0);
        return ret;
    }

    void bfs(vector<vector<int>> &ret, TreeNode *root, int level) {
        if (!root) return;
        if (level >= ret.size()) {
            ret.push_back({root->val});
        } else {
            ret[level].push_back(root->val);
        }

        bfs(ret, root->left, level + 1);
        bfs(ret, root->right, level + 1);
    }
};

class Que {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret{};

        std::deque<TreeNode *> q{};
        if (root) q.push_back(root);

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

            ret.push_back(v);
        }
        return ret;
    }
};
