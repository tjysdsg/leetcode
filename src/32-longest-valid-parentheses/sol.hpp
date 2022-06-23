// https://leetcode-cn.com/problems/longest-valid-parentheses/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::set;
using std::stack;

class SolutionStack {
public:
    int longestValidParentheses(string s) {
        int ret = 0;

        // the bottom element is the index of the last unmatched ')'
        // other elements are the indices of currently unmatched '('
        stack<int> stack;
        stack.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (c == '(')
                stack.push(i);
            else {
                stack.pop(); // always pop no matter stack top is ')' or '('
                if (stack.empty())
                    stack.push(i); // update the last unmatched ')'
                    // we don't need to update ret here
                else // match previous '('
                    // this covers two situation:
                    // 1. the top is an unmatched ')', so the string is: )xxxx)
                    // 2. the top is an unmatched '(', so the string is: ((xxxx)
                    ret = std::max(ret, i - stack.top());
            }
        }

        return ret;
    }
};
