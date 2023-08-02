#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countSubstrings("abc"), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countSubstrings("aaa"), 6);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countSubstrings("a"), 1);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countSubstrings("abcdcba"), 10);
}
