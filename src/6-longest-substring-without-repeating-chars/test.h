#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

SOLUTION_CLASS sol;

TEST(longest_substring, 1) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(longest_substring, 2) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(longest_substring, 3) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(longest_substring, 4) {
    EXPECT_EQ(sol.lengthOfLongestSubstring(""), 0);
}

TEST(longest_substring, 5) {
    EXPECT_EQ(sol.lengthOfLongestSubstring(" "), 1);
}

TEST(longest_substring, 6) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("au"), 2);
}

TEST(longest_substring, 7) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("aabaab!bb"), 3);
}

TEST(longest_substring, 8) {
    EXPECT_EQ(sol.lengthOfLongestSubstring("dvdf"), 3);
}
