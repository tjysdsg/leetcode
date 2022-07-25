#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<string> v{"2", "1", "+", "3", "*"};
    EXPECT_EQ(sol.evalRPN(v), 9);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<string> v{"4", "13", "5", "/", "+"};
    EXPECT_EQ(sol.evalRPN(v), 6);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<string> v{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(sol.evalRPN(v), 22);
}
