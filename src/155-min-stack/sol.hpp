// https://leetcode.cn/problems/min-stack/

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

// using no additional space, otherwise it's too simple
class MinStack {
private:
    // stores (val - min_value)
    stack<int64_t> _s{};
    int64_t _min_val = 0;

public:
    MinStack() {}

    void push(int x) {
        if (_s.empty()) {
            _s.push(0);
            _min_val = x;
            return;
        }

        if (x >= _min_val)
            _s.push(x - _min_val);
        else {
            _s.push(x - _min_val);
            _min_val = x;
        }
    }

    void pop() {
        assert(_s.size());

        int64_t top = _s.top();
        _s.pop();

        if (top < 0)
            _min_val -= top;
    }

    int top() {
        assert(_s.size());
        long top = _s.top();
        if (top < 0)
            return _min_val;
        return _min_val + _s.top();
    }

    int getMin() {
        assert(_s.size());
        return _min_val;
    }
};
