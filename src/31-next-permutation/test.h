#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 2, 3};
    sol.nextPermutation(v);
    EXPECT_THAT(v, ElementsAre(1, 3, 2));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 2, 1};
    sol.nextPermutation(v);
    EXPECT_THAT(v, ElementsAre(1, 2, 3));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 5};
    sol.nextPermutation(v);
    EXPECT_THAT(v, ElementsAre(1, 5, 1));
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3, 2};
    sol.nextPermutation(v);
    EXPECT_THAT(v, ElementsAre(2, 1, 3));
}
