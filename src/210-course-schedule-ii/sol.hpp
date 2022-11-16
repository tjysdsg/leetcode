// https://leetcode.cn/problems/course-schedule-ii/

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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> E(numCourses, vector<int>()); // E[i] = i -> j
        vector<int> n_in_edges(numCourses, 0); // # of in-edges of E[i]

        for (const auto &e: prerequisites) {
            // e[1] is the prerequisite, so edge is e[1] -> e[0]
            E[e[1]].push_back(e[0]);
            ++n_in_edges[e[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!n_in_edges[i]) // only search vertices with no in-edge (prerequisite)
                q.push(i);
        }

        vector<int> ret{};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ret.push_back(i);

            for (int j: E[i]) {
                // remove edge i -> j
                if (--n_in_edges[j] == 0)
                    q.push(j);
            }
        }

        if (ret.size() == numCourses)
            return ret;
        return {};
    }
};

class DFS {
    vector<vector<int>> E{}; // E[i] = vertices j that i -> j
    vector<int> status{}; // status[i]: 0 = not visited, 1 = visiting, 2 = visited
    vector<int> ret{};

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        ret.reserve(numCourses);
        E = vector<vector<int>>(numCourses, vector<int>());
        status = vector<int>(numCourses, 0);

        for (const auto &e: prerequisites) {
            // e[1] is the prerequisite, so edge is e[1] -> e[0]
            E[e[1]].push_back(e[0]);
        }

        bool valid = true;
        for (int i = 0; i < numCourses; ++i) {
            valid &= dfs(i);
            if (!valid) break;
        }

        if (valid) {
            std::reverse(ret.begin(), ret.end());
            return ret;
        } else {
            return {};
        }
    }

    bool dfs(int i) {
        if (2 == status[i]) return true;
        if (1 == status[i]) return false; // cycle detected

        status[i] = 1;
        for (int j: E[i]) {
            if (!dfs(j)) return false;
        }
        status[i] = 2;

        ret.push_back(i);
        return true;
    }
};
