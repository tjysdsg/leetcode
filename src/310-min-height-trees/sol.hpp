// https://leetcode.cn/problems/minimum-height-trees/

#pragma once

#include "common.h"

class DFS {
    unordered_map<int, vector<int>> edge_map{};

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n <= 1) return {0};

        for (const auto &e: edges) {
            edge_map[e[0]].push_back(e[1]);
            edge_map[e[1]].push_back(e[0]);
        }

        unordered_map<int, int> parent{};

        // x and y are the nodes whose parent is the longest in the graph
        int x = dfs(0, parent);
        parent.clear();
        int y = dfs(x, parent);

        vector<int> path{y};
        auto it = parent.find(y);
        while (it != parent.end()) {
            path.push_back(it->second);
            it = parent.find(it->second);
        }

        int length = path.size();
        assert(length >= 2);
        if (length % 2) {
            return {path[length / 2]};
        } else {
            return {path[length / 2], path[length / 2 - 1]};
        }
    }

    int dfs(int start, unordered_map<int, int> &parent) {
        int max_i = 0;
        int max_dist = 0;

        stack<pair<int, int>> q{};
        q.emplace(start, 0);
        unordered_set<int> visited{};

        while (!q.empty()) {
            auto curr = q.top();
            q.pop();
            int i = curr.first;
            int dist = curr.second;

            visited.insert(i);

            if (max_dist < dist) {
                max_i = i;
                max_dist = dist;
            }

            auto it = edge_map.find(i);
            if (it != edge_map.end()) {
                for (int j: it->second) {
                    if (i != j && visited.find(j) == visited.end()) {
                        q.emplace(j, dist + 1);
                        parent[j] = i;
                    }
                }
            }
        }

        return max_i;
    }
};
