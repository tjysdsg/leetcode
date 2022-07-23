// https://leetcode.cn/problems/implement-stack-using-queues/

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

class MinStack {
private:
    queue<int> _data{};
public:
    MinStack() {}

    void push(int x) {
        int n = _data.size();
        _data.push(x);
        for (int i = 0; i < n; ++i) {
            int e = _data.front();
            _data.pop();
            _data.push(e);
        }
    }

    int pop() {
        int ret = _data.front();
        _data.pop();
        return ret;
    }

    int top() {
        return _data.front();
    }

    bool empty() {
        return _data.empty();
    }
};
