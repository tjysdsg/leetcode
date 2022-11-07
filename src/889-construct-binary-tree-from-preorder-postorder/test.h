#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    sol.constructFromPrePost({1, 2, 4, 5, 3, 6, 7}, {4, 5, 2, 6, 7, 3, 1});
}
