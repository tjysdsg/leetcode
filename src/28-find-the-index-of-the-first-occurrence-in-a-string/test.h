#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.strStr("sadbutsad", "sad"), 0);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.strStr("leetcode", "leeto"), -1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.strStr("oionions", "onions"), 2);
}
