// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/

#pragma once

#include "common.h"

class Solution {
    /*
     * [#c, #r, #o, #a]
     */
    int croak_count[4]{};

public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ret = 0;
        int count = 0;
        for (char c: croakOfFrogs) {
            switch (c) {
                case 'c':
                    ++count;
                    ret = std::max(count, ret);
                    ++croak_count[0];
                    break;
                case 'r':
                    if (--croak_count[0] < 0) return -1;
                    ++croak_count[1];
                    break;
                case 'o':
                    if (--croak_count[1] < 0) return -1;
                    ++croak_count[2];
                    break;
                case 'a':
                    if (--croak_count[2] < 0) return -1;
                    ++croak_count[3];
                    break;
                case 'k':
                    if (--croak_count[3] < 0) return -1;
                    --count;
                    break;
                default:
                    return -1;
            }
        }
        if (count) return -1; // didn't finish a croak
        return ret;
    }
};
