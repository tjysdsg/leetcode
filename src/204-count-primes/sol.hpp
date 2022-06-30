// https://leetcode.cn/problems/count-primes/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cassert>
#include <unordered_map>

using std::string;
using std::cout;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::stack;

// TODO: Sieve of Eratosthenes
// TODO: dp?

class EulerSieve {
public:
    int countPrimes(int n) {
        vector<int> is_composite(n, 0);
        vector<int> primes;
        int ret = 0;

        for (int i = 2; i < n; ++i) {
            if (!is_composite[i]) {
                primes.push_back(i); // sorted by itself
                ++ret;
            }

            for (int p: primes) {
                if (i * p >= n) break;
                is_composite[i * p] = 1;
                if (i % p == 0) break; // key
            }
        }

        return ret;
    }
};
