// https://leetcode.cn/problems/group-anagrams/

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

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (string s: strs) {
            string key = s;
            std::sort(key.begin(), key.end());

            auto q = map.find(key);
            if (q != map.end())
                q->second.push_back(s);
            else
                map[key] = {s};
        }

        vector<vector<string>> ret;
        for (const auto &pair: map) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};
