// https://leetcode.cn/problems/my-calendar-i/

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
#include "common.h"

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;

// TODO: segment tree

class MyCalendar {
private:
    // start -> end
    map<int, int> m;
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = m.lower_bound(end);
        if (it != m.begin() && (--it)->second > start) {
            return false;
        }

        m[start] = end;
        return true;
    }
};
