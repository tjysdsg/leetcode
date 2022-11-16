// https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/

#pragma once

#include "common.h"

// union find
class Solution {
    vector<int> parent{};
    int ret = 0;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union_(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        --ret;
        parent[px] = py;
    }

public:
    int countComponents(int n, vector<vector<int>> &edges) {
        ret = n;
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (const auto &e: edges) {
            union_(e[0], e[1]);
        }

        return ret;
    }
};

class BFS {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n, vector<int>{});
        for (const auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited{};
        queue<int> q{};
        int ret = 0;
        for (int start = 0; start < n; ++start) {
            if (visited.find(start) != visited.end()) continue;

            ++ret;
            q.push(start);
            while (!q.empty()) {
                int i = q.front();
                q.pop();

                if (visited.find(i) != visited.end()) continue;
                visited.insert(i);

                for (int j: adj[i]) {
                    q.push(j);
                }
            }
        }
        return ret;
    }
};
