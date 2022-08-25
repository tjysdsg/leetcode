// https://leetcode.cn/problems/implement-queue-using-stacks/

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

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front = 0;

public:
    MyQueue() {}

    void push(int x) {
        if (s1.empty())
            front = x;
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }

    int peek() {
        if (s2.empty())
            return front;
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
