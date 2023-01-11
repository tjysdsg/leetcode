#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    vector<string> words{"apple"};
    SOLUTION_CLASS sol(words);
    EXPECT_EQ(0, sol.f("a", "e"));
}

TEST(test, 2) {
    vector<string> words{"apple", "apxle"};
    SOLUTION_CLASS sol(words);
    EXPECT_EQ(1, sol.f("a", "e"));
}

TEST(test, 3) {
    vector<string> words{"apple", "ale"};
    SOLUTION_CLASS sol(words);
    EXPECT_EQ(0, sol.f("ap", "e"));
}
