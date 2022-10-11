#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol(3);
    EXPECT_EQ(sol.next(1), 1);
    EXPECT_EQ(sol.next(10), 5.5);
    EXPECT_EQ(sol.next(3), 14.0 / 3.0);
    EXPECT_EQ(sol.next(5), 6.0);
}
