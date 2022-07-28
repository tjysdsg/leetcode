#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    sol.insert("apple");
    EXPECT_EQ(sol.search("apple"), true);
    EXPECT_EQ(sol.search("app"), false);
    EXPECT_EQ(sol.startsWith("app"), true);
    sol.insert("app");
    EXPECT_EQ(sol.search("app"), true);
}
