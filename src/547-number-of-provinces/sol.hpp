// https://leetcode.cn/problems/number-of-provinces/

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
using std::queue;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) {
        parent = vector<int>(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union_set(int a, int b) {
        parent[find(a)] = find(b);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        UnionFind u(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected[i][j]) {
                    u.union_set(i, j);
                }
            }
        }

        // cannot use std::set(u.parent).size() cuz some of u.parent is not updated by find()
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (u.parent[i] == i)
                ++ret;
        }
        return ret;
    }
};
