#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<string> ans{"((()))", "(()())", "(())()", "()(())", "()()()"};
    auto res = sol.generateParenthesis(3);
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<string> ans{"()"};
    auto res = sol.generateParenthesis(1);
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}
