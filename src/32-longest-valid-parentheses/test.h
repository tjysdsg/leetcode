#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

SOLUTION_CLASS sol;

TEST(longest_valid_parenthesis, 1) {
    int res = sol.longestValidParentheses("(()");
    EXPECT_EQ(res, 2);
}

TEST(longest_valid_parenthesis, 2) {
    int res = sol.longestValidParentheses(")()())");
    EXPECT_EQ(res, 4);
}

TEST(longest_valid_parenthesis, 3) {
    int res = sol.longestValidParentheses("0");
    EXPECT_EQ(res, 0);
}

TEST(longest_valid_parenthesis, 4) {
    int res = sol.longestValidParentheses("(()()(()()(()))(()))())(");
    EXPECT_EQ(res, 22);
}

TEST(longest_valid_parenthesis, 5) {
    int res = sol.longestValidParentheses("()(()");
    EXPECT_EQ(res, 2);
}

TEST(longest_valid_parenthesis, 6) {
    int res = sol.longestValidParentheses(")()(()())");
    EXPECT_EQ(res, 8);
}
