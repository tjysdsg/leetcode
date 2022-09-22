#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    int first_bad = 2;
    SOLUTION_CLASS sol(first_bad);
    EXPECT_EQ(sol.firstBadVersion(3), first_bad);
}

TEST(test, 1) {
    int first_bad = 4;
    SOLUTION_CLASS sol(first_bad);
    EXPECT_EQ(sol.firstBadVersion(5), first_bad);
}

TEST(test, 2) {
    int first_bad = 1;
    SOLUTION_CLASS sol(first_bad);
    EXPECT_EQ(sol.firstBadVersion(1), first_bad);
}

TEST(test, 3) {
    int first_bad = 2;
    SOLUTION_CLASS sol(first_bad);
    EXPECT_EQ(sol.firstBadVersion(2), first_bad);
}

TEST(test, 4) {
    int first_bad = INT_MAX;
    SOLUTION_CLASS sol(first_bad);
    EXPECT_EQ(sol.firstBadVersion(INT_MAX), first_bad);
}
