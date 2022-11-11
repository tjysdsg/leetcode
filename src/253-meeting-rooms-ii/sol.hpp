// https://leetcode.cn/problems/meeting-rooms-ii/

#pragma once

#include "common.h"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        enum Action {
            START,
            END,
        };
        vector<pair<int, Action>> flatten{};
        for (const auto &i: intervals) {
            flatten.emplace_back(i[0], START);
            flatten.emplace_back(i[1], END);
        }

        std::sort(flatten.begin(), flatten.end(), [&](const pair<int, Action> &a, const pair<int, Action> &b) {
            if (a.first == b.first) return a.second == END;
            return a.first < b.first;
        });
        int ret = 0;
        int count = 0;
        for (const auto &i: flatten) {
            Action act = i.second;

            if (act == END) --count;
            else ++count;

            ret = std::max(ret, count);
        }

        return ret;
    }
};
