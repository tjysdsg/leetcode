#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 2, 3, 3, 4, 4, 8, 8};
    EXPECT_EQ(sol.singleNonDuplicate(v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 3, 7, 7, 10, 11, 11};
    EXPECT_EQ(sol.singleNonDuplicate(v), 10);
}
