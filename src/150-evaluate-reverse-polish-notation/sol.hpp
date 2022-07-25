// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

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
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        for (const string &t: tokens) {
            switch (t[t.length() - 1]) {
                case '+':
                    b = s.top();
                    s.pop();
                    a = s.top();
                    s.pop();
                    s.push(a + b);
                    break;
                case '-':
                    b = s.top();
                    s.pop();
                    a = s.top();
                    s.pop();
                    s.push(a - b);
                    break;
                case '*':
                    b = s.top();
                    s.pop();
                    a = s.top();
                    s.pop();
                    s.push(a * b);
                    break;
                case '/':
                    b = s.top();
                    s.pop();
                    a = s.top();
                    s.pop();
                    s.push(a / b);
                    break;
                default:
                    s.push(std::stoi(t));
                    break;
            }
        }

        return s.top();
    }
};
