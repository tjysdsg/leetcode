#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    EXPECT_EQ(sol.book(10, 20), true);
    EXPECT_EQ(sol.book(15, 25), false);
    EXPECT_EQ(sol.book(20, 30), true);
}
