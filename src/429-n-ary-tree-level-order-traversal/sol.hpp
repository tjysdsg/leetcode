// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/

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
#include <unordered_set>
#include <queue>
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::set;
using std::stack;
using std::queue;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> q;
        vector<vector<int>> ret;

        if (root)
            q.push(root);

        vector<int> level;
        while (!q.empty()) {
            int n = q.size();

            level.clear();
            level.reserve(n);
            for (int i = 0; i < n; ++i) {
                Node *curr = q.front();
                q.pop();

                if (curr) {
                    level.push_back(curr->val);
                    for (auto *ch: curr->children) {
                        q.push(ch);
                    }
                }
            }

            ret.push_back(level);
        }
        return ret;
    }
};
