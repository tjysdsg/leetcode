#pragma once
#include "13-roman-to-integer.hpp"
#include <gtest/gtest.h>

TEST(roman_to_integer, 1) {
  string in = "III";
  int out = 3;
  Solution sol;
  EXPECT_EQ(sol.romanToInt(in), out);
}

TEST(roman_to_integer, 2) {
  string in = "LVIII";
  int out = 58;
  Solution sol;
  EXPECT_EQ(sol.romanToInt(in), out);
}

TEST(roman_to_integer, 3) {
  string in = "MCMXCIV";
  int out = 1994;
  Solution sol;
  EXPECT_EQ(sol.romanToInt(in), out);
}
