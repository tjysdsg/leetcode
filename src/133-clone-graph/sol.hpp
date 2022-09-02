// https://leetcode.cn/problems/clone-graph/

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
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node *, Node *> seen{};

public:
    Node *cloneGraph(Node *node) {
        seen.clear();
        return clone(node);
    }

    Node *clone(Node *node) {
        if (!node)
            return nullptr;

        auto q = seen.find(node);
        if (q != seen.end())
            return q->second;

        Node *ret = new Node(node->val);
        seen[node] = ret;
        for (Node *n: node->neighbors) {
            ret->neighbors.push_back(clone(n));
        }

        return ret;
    }
};
