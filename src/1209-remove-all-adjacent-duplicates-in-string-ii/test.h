#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.removeDuplicates("abcd", 2), "abcd");
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.removeDuplicates("deeedbbcccbdaa", 3), "aa");
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.removeDuplicates("pbbcggttciiippooaais", 2), "ps");
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.removeDuplicates("p", 2), "p");
}
