#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(count_primes, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countPrimes(10), 4);
}

TEST(count_primes, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countPrimes(0), 0);
}

TEST(count_primes, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countPrimes(1), 0);
}

TEST(count_primes, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.countPrimes(5000000), 348513);
}
