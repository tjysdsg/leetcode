// https://leetcode.cn/problems/time-based-key-value-store/

#pragma once

#include "common.h"

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        auto it = m.find(key);
        if (it != m.end()) {
            it->second.emplace_back(timestamp, value);
        } else {
            vector<pair<int, string>> v{std::make_pair(timestamp, value)};
            m.emplace(key, std::move(v));
        }
    }

    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it == m.end())
            return "";

        const auto &v = it->second;
        string ret = "";
        search(v, timestamp, 0, v.size() - 1, ret);
        return ret;
    }

    void search(const vector<pair<int, string>> &v, int timestamp, int start, int end, string &ans) {
        if (start < end) {
            int mid = (start + end) / 2;
            int t = v[mid].first;
            if (t == timestamp) {
                ans = v[mid].second;
                return;
            } else if (timestamp < t) {
                search(v, timestamp, start, std::max(start, mid - 1), ans);
            } else {
                search(v, timestamp, std::min(end, mid + 1), end, ans);
                if (ans == "")
                    ans = v[mid].second;
            }
        } else {
            if (v[start].first <= timestamp)
                ans = v[start].second;
        }
    }
};
