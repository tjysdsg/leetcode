#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.intToRoman(3), "III");
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.intToRoman(58), "LVIII");
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.intToRoman(1994), "MCMXCIV");
}
