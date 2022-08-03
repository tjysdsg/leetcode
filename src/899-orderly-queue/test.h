#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.orderlyQueue("cba", 1), "acb");
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.orderlyQueue("baaca", 3), "aaabc");
}
