// https://leetcode.cn/problems/course-schedule-iii

#pragma once

#include "common.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        std::sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int time = 0;
        priority_queue<int> q{};

        for (const auto &c: courses) {
            int dur = c[0];
            int ddl = c[1];

            if (time + dur <= ddl) { // can finish current course
                time += dur;
                q.push(dur);
            } else if (!q.empty() && q.top() > dur) { // can't, backtrack, replace the longest course
                time = time - q.top() + dur;
                q.pop();
                q.push(dur);
            }
        }

        return q.size();
    }
};
