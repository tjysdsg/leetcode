// https://leetcode.cn/problems/course-schedule/

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

/*
 * Two topological sorting methods
 */


class BFS {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> E(numCourses, vector<int>()); // E[i] = i -> j
        vector<int> n_in_edges(numCourses, 0); // # of in-edges of E[i]

        for (const auto &e: prerequisites) {
            // e[1] is the prerequisite, so edge is e[1] -> e[0]
            E[e[1]].push_back(e[0]);
            ++n_in_edges[e[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!n_in_edges[i]) // only search vertices with no out-edge
                q.push(i);
        }

        int n_visited = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ++n_visited;

            for (int j: E[i]) {
                // remove edge i -> j
                if (--n_in_edges[j] == 0)
                    q.push(j);
            }
        }

        return n_visited == numCourses;
    }
};

class DFS {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> E(numCourses, vector<int>()); // E[i] = vertices j that i -> j
        vector<int> status(numCourses, 0); // status[i]: 0 = not visited, 1 = visiting, 2 = visited

        for (const auto &e: prerequisites) {
            // e[1] is the prerequisite, so edge is e[1] -> e[0]
            E[e[1]].push_back(e[0]);
        }

        bool ret = true;
        for (int i = 0; i < numCourses; ++i) {
            ret &= dfs(i, E, status);
            if (!ret) break;
        }

        return ret;
    }

    bool dfs(int i, const vector<vector<int>> &E, vector<int> &status) {
        if (2 == status[i]) return true;
        if (1 == status[i]) return false; // cycle detected

        status[i] = 1;
        for (int j: E[i]) {
            if (!dfs(j, E, status)) return false;
        }
        status[i] = 2;

        return true;
    }
};
