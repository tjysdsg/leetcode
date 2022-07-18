#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto ret = sol.letterCombinations("23");
    EXPECT_THAT(ret, UnorderedElementsAre("ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto ret = sol.letterCombinations("");
    EXPECT_THAT(ret, UnorderedElementsAre());
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto ret = sol.letterCombinations("2");
    EXPECT_THAT(ret, UnorderedElementsAre("a", "b", "c"));
}
