#pragma once
#include "13-roman-to-integer.hpp"
#include <gtest/gtest.h>

TEST(roman_to_integer, all) {
  string in = "III";
  int out = 3;
  Solution sol;

  EXPECT_EQ(sol.romanToInt(in), out);
}
