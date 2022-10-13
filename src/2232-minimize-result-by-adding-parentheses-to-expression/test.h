#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.minimizeResult("247+38"), "2(47+38)");
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.minimizeResult("12+34"), "1(2+3)4");
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.minimizeResult("999+999"), "(999+999)");
}
