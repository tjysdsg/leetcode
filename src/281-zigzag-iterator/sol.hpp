// https://leetcode.cn/problems/zigzag-iterator/

#pragma once

#include "common.h"

/// Generic solution that also works for the follow up question
class ZigzagIterator {
private:
    using safe_it = pair<vector<int>::iterator, vector<int>::iterator>;
    queue<safe_it> q;

public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        if (!v1.empty())
            q.emplace(v1.begin(), v1.end());
        if (!v2.empty())
            q.emplace(v2.begin(), v2.end());
    }

    ZigzagIterator(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
        if (!v1.empty())
            q.emplace(v1.begin(), v1.end());
        if (!v2.empty())
            q.emplace(v2.begin(), v2.end());
        if (!v3.empty())
            q.emplace(v3.begin(), v3.end());
    }

    int next() {
        auto i = q.front();
        q.pop();

        int ret = *i.first;

        if (++i.first != i.second) {
            q.push(i);
        }
        return ret;
    }

    bool hasNext() {
        return !q.empty();
    }
};
