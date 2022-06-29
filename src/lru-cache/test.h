#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>


TEST(lru_cache, 1) {
    SOLUTION_CLASS sol(2);
    sol.put(1, 1);
    sol.put(2, 2);

    EXPECT_EQ(sol.get(1), 1);
    sol.put(3, 3);
    EXPECT_EQ(sol.get(2), -1);
    sol.put(4, 4);
    EXPECT_EQ(sol.get(1), -1);
    EXPECT_EQ(sol.get(3), 3);
    EXPECT_EQ(sol.get(4), 4);
}
