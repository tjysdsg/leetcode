#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.decodeString("3[a]2[bc]"), "aaabcbc");
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.decodeString("3[a2[c]]"), "accaccacc");
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
}
