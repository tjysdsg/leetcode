#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.isValid("()"), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.isValid("()[]{}"), true);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.isValid("(]"), false);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.isValid("("), false);
}
