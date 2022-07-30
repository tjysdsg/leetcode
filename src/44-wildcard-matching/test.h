#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

SOLUTION_CLASS sol;

TEST(regular_expression_matching, 0) {
    bool res = sol.isMatch("aa", "*");
    EXPECT_DOUBLE_EQ(res, true);
}

TEST(regular_expression_matching, 1) {
    bool res = sol.isMatch("aa", "a");
    EXPECT_DOUBLE_EQ(res, false);
}

TEST(regular_expression_matching, 2) {
    bool res = sol.isMatch("aa", "*");
    EXPECT_DOUBLE_EQ(res, true);
}

TEST(regular_expression_matching, 3) {
    bool res = sol.isMatch("cb", "?a");
    EXPECT_DOUBLE_EQ(res, false);
}

TEST(regular_expression_matching, 4) {
    bool res = sol.isMatch("ba", "?a");
    EXPECT_DOUBLE_EQ(res, true);
}

TEST(regular_expression_matching, 5) {
    bool res = sol.isMatch("cba", "?a");
    EXPECT_DOUBLE_EQ(res, false);
}

TEST(regular_expression_matching, 6) {
    bool res = sol.isMatch("cba", "*a");
    EXPECT_DOUBLE_EQ(res, true);
}

TEST(regular_expression_matching, 7) {
    bool res = sol.isMatch("adceb", "*a*b");
    EXPECT_DOUBLE_EQ(res, true);
}

