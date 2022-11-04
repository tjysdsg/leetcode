// https://leetcode.cn/problems/employee-free-time

#pragma once

#include "common.h"

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};


// TODO: priority queue

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int, bool>> timestamps{};
        vector<Interval> ret{};

        for (const auto &v: schedule) {
            for (const auto &i: v) {
                timestamps.emplace_back(i.start, true);
                timestamps.emplace_back(i.end, false);
            }
        }
        std::sort(timestamps.begin(), timestamps.end());

        int n_working = 0;
        int prev_time = -1;
        for (const auto &i: timestamps) {
            int time = i.first;
            bool work = i.second;

            if (prev_time != -1 && n_working == 0 && prev_time != time) {
                ret.emplace_back(prev_time, time);
            }

            n_working += work ? 1 : -1;
            if (!work) prev_time = time;
        }

        return ret;
    }
};

#define INTERVAL_MAX 100000000

class Stupid {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> free{
                Interval(-INTERVAL_MAX, INTERVAL_MAX),
        };

        int n_employees = schedule.size();
        vector<int> rm{};

        for (int f = 0; f < free.size(); ++f) {
            if (free[f].start == -1)
                continue;

            for (int e = 0; e < n_employees; ++e) {
                auto e_sch = schedule[e];

                for (int i = 0; i < e_sch.size(); ++i) {
                    int e_start = e_sch[i].start;
                    int e_end = e_sch[i].end;
                    int f_start = free[f].start;
                    int f_end = free[f].end;

                    // e then f
                    if (f_start < e_end && f_start >= e_start) {
                        // overlap
                        if (f_end >= e_end) {
                            free[f].start = e_end;
                        } else { // e includes f
                            free[f].start = -1;
                            free[f].end = -1;
                            rm.push_back(f);
                        }
                    } else if (e_start <= f_end && e_start > f_start) { // f then e
                        if (e_end >= f_end) { // overlap
                            free[f].end = e_start;
                        } else { // f includes e
                            free[f].end = e_start;
                            free.push_back({e_end, f_end});
                        }
                    }
                }
            }
        }

        for (int i = free.size() - 1; i >= 0; --i) {
            if (free[i].start == -1 || std::abs(free[i].start) == INTERVAL_MAX ||
                std::abs(free[i].end) == INTERVAL_MAX || free[i].start == free[i].end)
                free.erase(free.begin() + i);
        }

        std::sort(free.begin(), free.end(), [&](const Interval &a, const Interval &b) { return a.start < b.start; });
        return free;
    }
};
