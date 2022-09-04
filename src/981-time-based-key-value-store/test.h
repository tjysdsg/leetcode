#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;

    sol.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1.
    EXPECT_EQ(sol.get("foo", 1), "bar");
    EXPECT_EQ(sol.get("foo", 3), "bar");
    sol.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    EXPECT_EQ(sol.get("foo", 4), "bar2"); // return "bar2"
    EXPECT_EQ(sol.get("foo", 5), "bar2"); // return "bar2"
}

TEST(test, 2) {
    SOLUTION_CLASS sol;

    sol.set("love", "high", 10);
    sol.set("love", "low", 20);
    EXPECT_EQ(sol.get("love", 5), "");
    EXPECT_EQ(sol.get("love", 10), "high");
    EXPECT_EQ(sol.get("love", 15), "high");
    EXPECT_EQ(sol.get("love", 20), "low");
    EXPECT_EQ(sol.get("love", 25), "low");
}
